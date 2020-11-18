#include "splashkit.h"
#include <string.h>

using std::string;

namespace CT
{
    // Get user input as text
    string read_string(string prompt)
    {
        write(prompt);
        string input = read_line();
        return input;
    }

    // Get user input as integer
    int read_integer(string prompt)
    {
        string input = read_string(prompt);

        while(not is_integer(input))
        {
            write_line("Invalid input. Enter an Integer.");
            input = read_string(prompt);
        }

        int value = convert_to_integer(input);
        return value;
    }

    // Get user input as integer between two numbers
    int read_integer(string prompt, int min, int max)
    {
        int result;

        result = read_integer(prompt);

        while(result < min or result > max)
        {
            write_line("Invalid number. Enter a number between " + std::to_string(min) + " and " + std::to_string(max));
            result = read_integer(prompt);
        }

        return result;
    }

    // Get user input as double
    double read_double(string prompt)
    {
        string input = read_string(prompt);

        while(not is_double(input))
        {
            write_line("Invalid value. Enter a valid decimal number.");
            input = read_string(prompt);
        }

        double value = convert_to_double(input);
        return value;
    }

    // Get user input as double within range 
    double read_double(string prompt, double min, double max)
    {
        double result;

        result = read_double(prompt);

        while(result < min or result > max)
        {
            write_line("Invalid value. Enter a number between " + std::to_string(min) + " and " + std::to_string(max));
            result = read_double(prompt);
        }

        return result;
    }

    // Get user input as bool
    bool read_boolean(string prompt)
    {
        string input = to_lowercase(trim(read_string(prompt)));

        while(input != "y" and input != "yes" and input != "n" and input != "no")
        {
            write_line("Invalid value. Enter Yes or No.");
            input = to_lowercase(trim(read_string(prompt)));
        }

        // Return boolean value
        if(input == "y" or input == "yes")
        {
            return true;
        } else
        {
            return false;
        }
    }

    // Renaming the empty write_line procedure for symantics
    void line_break()
    {
        write_line();
    }

    // Pause the operation of the application
    void pause()
    {
        line_break();
        read_string("Press enter to continue...");
        line_break();
    }

    // Get and confirm password from user
    string input_password()
    {
        string pwd, pwd_conf;
        int compare_result = -1;
        do
        {
            pwd = read_string("Enter password: ");
            pwd_conf = read_string("Confirmed password: ");
            line_break();

            compare_result = pwd.compare(pwd_conf);
            if(compare_result != 0)
            {
                write_line("Passwords do not match!");
                line_break();
            } else if (pwd.length() < 8)
            {
                write_line("Password must be between 8 and 255 characters long.");
                line_break();
            }
        } while (compare_result != 0 || pwd.length() < 8 || pwd.length() > 255);
        
        return pwd;
    }
}