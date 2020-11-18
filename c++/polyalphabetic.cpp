#include <stdio.h>
#include <cstring>
#include <ctype.h>
#include <stdlib.h>

const char* KEYWORDS[3] = {
            "VIGENERE",
            "POLYALPHABETIC",
            "CIPHER"};

namespace polyalphabetic
{
    // Transform key into defined length
    char* expandKey(const char* key, const int length)
    {
        int key_length = strlen(key);
        char* expanded_key = (char*)calloc(1, length + 1);

        for (int i = 0; i < length; i++) 
        { 
            expanded_key[i] = key[i % key_length];
        }
        return expanded_key; 
    } 
    
    // Function to encrypt an input using a single key - encryption round
    char* encrypt_round(const char* input, const char* key) 
    {
        int length = strlen(input);
        char* cipher_text = (char*)calloc(1, length + 1);   
    
        char temp_ch;
        for (int i = 0; i < length; i++) 
        {
            if(isalpha(input[i]))
            {
                if(isupper(input[i]))
                { 
                    temp_ch = (((input[i] - 65) + (toupper(key[i]) - 65)) % 26) + 65;
                } else
                {
                    temp_ch = (((input[i] - 97) + (tolower(key[i]) - 97)) % 26) + 97;
                }
                cipher_text[i] = temp_ch;
            } else 
            {
                cipher_text[i] = input[i];
            }
            
        } 
        return cipher_text; 
    } 
    
    // Function to decrypt an input using a single key - decryption round
    char* decrypt_round(const char* input, const char* key) 
    { 
        int length = strlen(input);
        char* output = (char*)calloc(1, length+1);
        char temp_ch;

        for (int i = 0 ; i < length; i++) 
        {
            if(isalpha(input[i]))
            {
                if(isupper(input[i]))
                {
                    temp_ch = (((((input[i] - 65) - (toupper(key[i]) - 65)) + 26) % 26) + 65);
                } else {
                    temp_ch = (((((input[i] - 97) - (tolower(key[i]) - 97)) + 26) % 26) + 97);
                }
                output[i] = temp_ch;
            } else {
                output[i] = input[i];
            }
        }
        return output; 
    }

    // Encryption function to manage the rounds of encryption
    char* encrypt(const char* input)
    {
        char* key;
        char* output = (char*)calloc(1, strlen(input)+1);
        memcpy(output, input, strlen(input));
        for(int i = 0; i < 3; i++)
        {
            key = polyalphabetic::expandKey(KEYWORDS[i], strlen(input));
            output = polyalphabetic::encrypt_round(output, key);
        }
        return output;
    }

    // Decryption function to manage to rounds of decryption
    char* decrypt(const char* input)
    {
        char* key;
        char* output = (char*)calloc(1, strlen(input)+1);
        memcpy(output, input, strlen(input));
        for(int i = 2; i >= 0; i--)
        {
            key = polyalphabetic::expandKey(KEYWORDS[i], strlen(input));
            output = polyalphabetic::decrypt_round(output, key);
        }
        return output;
    }
}