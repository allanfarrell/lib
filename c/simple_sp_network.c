#ifndef SIMPLE_SP_NETWORK
#define SIMPLE_SP_NETWORK

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

// Subsitute every chaaracter in the string
char* substitute(char* input, char* operation)
{
    // Calloc space to store substitution text
    char* sub_text = (char*)calloc(1, strlen(input));
    // ASCII array
    const char* ascii_characters = "!\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~";
    // ASCII substitute array
    const char* substitution_characters = ",%e'O1}(9#s!QW.@{lv/E<gA)wuU\"jH3$4D:ItK?\\26ZLR`f&GkyoXbP[ThdYn;+_-Bam^]Cc>~NS8zVM57J|r=*x0ipFq";

   // Initialise pointers
    char* pointer;
    char* r_pointer;

    // Loop through all values in the input array
    for (int i = 0; i < strlen(input); i++)
    {
        pointer = strchr(ascii_characters, input[i]);
        r_pointer = strchr(substitution_characters, input[i]);

        // Encrypt input
        if (strcmp(operation, "encrypt") == 0)
        {
            if (pointer == NULL)
            {
                sub_text[i] = input[i];
            }
            else
            {
                sub_text[i] = substitution_characters[pointer - ascii_characters];
            }
        }
        // Decrypt input
        else if (strcmp(operation, "decrypt") == 0)
        {
            if (r_pointer == NULL)
            {
                sub_text[i] = input[i];
            }
            else
            {
                sub_text[i] = ascii_characters[r_pointer - substitution_characters];
            }
        }
    }
    return sub_text;
}

// Change every second binary digit
char* permutate(char* sub_text)
{
    // Allocate memory to store result
    char* perm_text = (char*)calloc(strlen(sub_text));

    // Loop  through every value in the array
    for (int i = 0; i < strlen(sub_text); i++)
    {
        // Copy value
        perm_text[i] = sub_text[i];
        // Exclusive OR (XOR) char with 0b01010101
        perm_text[i] ^= 'U';
    }
    return perm_text;
}

#endif