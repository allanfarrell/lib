defmodule Rate_limiter do
  use GenServer

  @moduledoc """
    Limits number of concurrent connections to the server using a sliding window.
  """

  # Start Rate Limit Management Server on application start
  @spec start_link( any() ) :: { :ok, pid() } | :ignore | { :error, { :already_started, pid() } | term() }
  def start_link( _ ) do
    GenServer.start_link( __MODULE__, %{}, name: __MODULE__ )
  end

  # Default process called on server start
  @spec init( map ) :: { :ok, map }
  def init( _state ) do
    state = %{
      conn: [],
      config: %{
        max_window_conn: Application.get_env(:ldc, Ldc.Rate_limiter, "max_window_conn"),
        max_user_conn: Application.get_env(:ldc, Ldc.Rate_limiter, "max_user_conn"),
        max_ip_conn: Application.get_env(:ldc, Ldc.Rate_limiter, "max_ip_conn"),
        time_period: Application.get_env(:ldc, Ldc.Rate_limiter, "time_period")
      }
    }
    # Add work to be done on start up
    { :ok, state }
  end

  @doc """
    Update the rate limiter window time period
    Add new connection
  """
  @spec manage_rate( String.t, String.t ) :: { :error, String.t} | { :reply, :ok, map }
  def manage_rate( uuid, ip ) do
    GenServer.call( __MODULE__, { :manage_rate, uuid, ip } )
  end

  @doc """
    GenServer handler for manage_rate function - syncronous
  """
  @spec handle_call( { atom, String.t, String.t }, String.t, map )  :: { :error, String.t} | { :reply, :ok, map }
  def handle_call( { :manage_rate, uuid, ip }, _from, state ) do
    current_timestamp = DateTime.utc_now()

    # Slide window
    slide_window( state, current_timestamp )

    if check_window_usage( state ) == :ok do
      if check_user_usage( state, uuid ) == :ok do
        if check_ip_usage( state, ip ) == :ok do
          # Add conn to list
          add_conn( state, uuid, ip, current_timestamp )

          # Return result
          { :reply, :ok, state }
        else
          { :error, message: "Connection limit exceed from IP address." }
        end
      else
        { :error, message: "Connection limit exceed for user account." }
      end
    else
      { :error, message: "Connection limit exceeded." }
    end
  end

  @doc """
    # Slide window
    Update window time period
    Remove connections from outside of this time period
  """
  @spec slide_window( map, DateTime ) :: map
  defp slide_window( state, current_timestamp ) do
    # Update window usage
    case Map.fetch( state, :max_window_conn ) do
      { :ok, result } ->
        Enum.drop_while( result, fn window_conn -> window_conn.timestamp < current_timestamp - state.config.time_period end )
      _ ->
        state
    end
  end

  @doc """
    Check total number of connections does not exceed the limit
  """
  @spec check_window_usage( map ) :: :ok | :error
  defp check_window_usage( state ) do
    count =
    state.conn
    |> Enum.count

    case count do
      count when count >= state.config.max_window_conn -> :error
      _ -> :ok
    end
  end

  @doc """
    Check number of user connections in time period does not exceed the limit
  """
  @spec check_user_usage( map, String.t ) :: :ok | :error
  defp check_user_usage( state, uuid ) do
    count =
    state.conn
    |> Enum.count( fn item -> item.uuid == uuid end )

    case count do
      count when count >= state.config.max_user_conn -> :error
      _ -> :ok
    end
  end

  @doc """
    Check number of ip connections in time period does not exceed the limit
  """
  @spec check_ip_usage( map, String.t ) :: :ok | :error
  defp check_ip_usage( state, ip ) do
    count =
    state.conn
    |> Enum.count( fn item -> item.ip == ip end )

    case count do
      count when count >= state.config.max_ip_conn -> :error
      _ -> :ok
    end
  end

  @doc """
    Add connection to the list of connections in server state
  """
  @spec add_conn( map, String.t, String.t, String.t ) :: no_return()
  defp add_conn( state, uuid, ip, timestamp ) do
    state.conn ++ [ %{ uuid: uuid, ip: ip, timestamp: timestamp } ]
  end
end
