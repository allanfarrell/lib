//	Convert HEX -> ASCII (int) -> String
//	48656c6c6f20576f726c6421
//	HEX -> ASCII (int)
//		Map HEX value to int
//		Concatenate values to ensure ASCII character		

//	Convert String -> ASCII (int) -> HEX
//	Hello world!
//	String -> ASCII (int) by default
//		Break down int into individul values i.e. 49 -> 4 / 9
//		Map individual value to HEX

#include <stdio.h>
#include <string.h>
#include <cstdlib>
#include <ctype.h>

const int hex_map[2][16] = {
	{'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'},
	{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15}
};

// Convert a pair of hex values into a ASCII character
int convert_hex_pair(char hex_one, char hex_two)
{
	unsigned int temp = 0;
	int value1, value2;
	for (int i = 0; i < 16; i++)
	{
		if(tolower(hex_one) == hex_map[0][i])
		{
			value1 = hex_map[1][i];
		}
		if(tolower(hex_two) == hex_map[0][i])
		{
			value2 = hex_map[1][i];
		}
	}
		temp = (unsigned int) value1 << 4;
		temp += (unsigned int) value2;
	return temp;
}

// Convert a hex string into a ASCII string
char* hex_to_ascii(char* hex_string)
{
	int str_len = strlen(hex_string);
	char* char_array = (char*)malloc(str_len / 2);

	for(int i = 0, j = 0; i < str_len; i += 2, j++)
	{
		char_array[j] = convert_hex_pair(hex_string[i], hex_string[i+1]);
	}

	return char_array;
}

// Convert ascii character to a pair of hex characters
void convert_ascii_value(char ascii_value, char* hex_sub_array)
{	
	// Shift the bits in positions 5 - 8 to positions 1 - 4, disgard original values
	int temp = ascii_value >> 4;

	// Change the first bits in positions 5 - 8 to zero
	int temp2 = ascii_value & ~(0b11110000);

	// Loop through hex map
	for(int i = 0; i < 16; i++)
	{
		// Match temp values to hex map
		if(temp == hex_map[1][i])
		{
			// Store corresponding values in hex sub array
			hex_sub_array[0] = hex_map[0][i];
		}
		// Match temp values to hex map
		if(temp2 == hex_map[1][i])
		{
			// Store corresponding values in hex sub array
			hex_sub_array[1] = hex_map[0][i];
		}
	}
}

//Convert an ASCII string to a hex string
char* ascii_to_hex(char* ascii_string)
{
	// Get number of characters in string (note: strings are terminated by '/0' - not included in the count)
	int str_len = strlen(ascii_string);
	
	// Create empty array to store converted value
	char* char_array = (char*)calloc(1, (str_len * 2) + 1);

	// Loop through all characters in ASCII string
	for (int i = 0, j = 0; ascii_string[i] != '\0'; i++, j += 2)
	{
		// Convert each value to two hex values
		convert_ascii_value(ascii_string[i], &char_array[j]);
	}

	// Add String terminator to the end of the array
	char_array[str_len*2 + 1] = '\0';

	return char_array;
}

// Main program turn on
int main()
{
	printf("Convert hex value: 48656c6c6f20576f726c6421 to ASCII\n");
	char* string2 = "48656c6c6f20576f726c6421";
	char* output = hex_to_ascii(string2);
	printf("%s\n", output);	

	printf("Convert ASCII value: 'Hello World!' to hex\n");
	char* string3 = "Hello World!";
	char* output3 = ascii_to_hex(string3);
	printf("%s\n", output3);
}