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
char* convert_ascci_value(char* ascii_value)
{
	// TO BE COMPLETED
	char* char_array = "";
	return char_array;
}

//Convert an ASCII string to a hex string
char* ascii_to_hex(char* ascii_string)
{
	// TO BE COMPLETED
	int str_len = strlen(ascii_string);
	char* char_array = (char*)malloc(str_len / 2);
	return char_array;
}

// Main program turn on
int main()
{
	// Hello World!
	char* string2 = "48656c6c6f20576f726c6421";
	char* output = hex_to_ascii(string2);
	printf("%s", output);	
}