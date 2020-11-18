#ifndef HEX_CONVERTER
#define HEX_CONVERTER

// Convert a pair of hex values into a ASCII character
int convert_hex_pair(const char hex_one, const char hex_two);

// Convert a hex string into a ASCII string
char* hex_to_ascii(const char* hex_string);

// Convert ascii character to a pair of hex characters
void convert_ascii_value(const char ascii_value, char* hex_sub_array);

//Convert an ASCII string to a hex string
char* ascii_to_hex(const char* ascii_string);

#endif