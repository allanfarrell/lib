#ifndef COMMON_TERMINAL
#define COMMON_TERMINAL

# include <string>
using std::string;

namespace CT
{
    /**
     * Displays a message to the user to prompt the user to enter appropriate information
     * in the Terminal window. Records the input that the user inputs and returns the value.
     * 
     * param prompt    The message displayed to the user to prompt user input
     * return          The text the user has entered as a string
     */
    string read_string(string prompt);

    /**
     * Displays a message to the user to prompt the user to enter an integer (whole number)
     * in the Terminal window. Records the input that the user inputs and returns the value.
     * 
     * param prompt    The message displayed to the user to prompt user input
     * return          The number the user has entered as a integer
     */
    int read_integer(string prompt);

    /**
     * Displays a message to the user to prompt the user to enter an integer (whole number) 
     * within a specified range in the Terminal window. Records the input that the user inputs
     * and returns the value.
     * 
     * param prompt    The message displayed to the user to prompt user input
     * param min       Minimum value of integer
     * param max       Maximum value of integer
     * return          The number the user has entered as a integer
     */
    int read_integer(string prompt, int min, int max);

    /**
     * Displays a message to the user to prompt the user to enter numerical value
     * within a specified range in the Terminal window. Records the input that the
     * user inputs and returns the value.
     * 
     * param prompt    The message displayed to the user to prompt user input
     * return          The number the user has entered as a double e.g. 0.00000
     */
    double read_double(string prompt);

    /**
     * Displays a message to the user to prompt the user to enter numerical value
     * in the Terminal window. Records the input that the user inputs and returns the value.
     * 
     * param prompt    The message displayed to the user to prompt user input
     * param min       Minimum value of double
     * param max       Maximum value of double
     * return          The number the user has entered as a double e.g. 0.00000
     */
    double read_double(string prompt, double min, double max);

    /**
     * Displays a message to the user to prompt the user to enter boolean value (Yes or No)
     * in the Terminal window. Records the input that the user inputs and returns the value.
     * 
     * param prompt    The message displayed to the user to prompt user input
     * return          The number the user has entered as a boolean e.g. True/False
     */
    bool read_boolean(string prompt);

    /**
     * Wrapper around the empty write_line() procedure to rename it
     * to make code more symantic
     * 
     * This procedure does not take any input or return any value
     */
    void line_break();

    /**
     * Pauses the running of the terminal window, requiring the user to press enter
     * to continue with the applications execution
     * 
     * This procedure does not take any input or return any value
     */
    void pause();

    /**
     * Get and confirm password from user
     * 
     * This procedure does not take any input
     * @return      Returns a string of the confirmed password
     */
    string input_password();
}

#endif