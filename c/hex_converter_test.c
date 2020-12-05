#include <stdio.h>
#include <string.h>
#include <cstdlib>
#include <ctype.h>
#include "hex_converter.h"

void test_ascii_to_hex()
{
	printf("Convert ASCII value: 'Hello World!' to hex\n");
	// Arrange
	char* string = "Hello World!";

	// Act
	char* output = ascii_to_hex(string);

	// Assert
	if(strcmp(string, output) == 0)
	{
		printf("Test 1 passed!");
	} else
	{
		printf("Test 1 failed!");
	}
}

void test_hex_to_ascii()
{
	printf("Convert hex value: 48656c6c6f20576f726c6421 to ASCII\n");
	// Arrange
	char* string = "48656c6c6f20576f726c6421";

	// Act
	char* output = hex_to_ascii(string);

	// Assert
	if(strcmp(string, output) == 0)
	{
		printf("Test 2 passed!");
	} else
	{
		printf("Test 2 failed!");
	}
}

// Main program turn on
int main()
{
	test_ascii_to_hex();
	test_hex_to_ascii();
}