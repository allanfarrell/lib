#include <stdio.h>
#include <string.h>
#include <cstdlib>
#include <ctype.h>
#include "hex_converter.h"

// TO DO
// Write test cases
	// Arrange
	// Act
	// Assert

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

