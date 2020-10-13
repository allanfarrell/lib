#include <string>
#include <cstring>

char* substitute(const char* input, const char* flag)
{
    printf("\n****** Substitute *****\n");
    char* output = (char*)calloc(1, strlen(input));
    // ASCII table symbols
    const char* original_alphabet = " !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~";
    const char* substitution_alphabet = ",%e'O1}(9#s!QW.@{lv/E<gA)wuU\"jH3$4D:ItK?\\26 ZLR`f&GkyoXbP[ThdYn;+_-Bam^]Cc>~NS8zVM57J|r=*x0ipFq";

    char* ch_ptr;
    for(int i = 0; i < strlen(input); i++)
    {
        if(strcmp(flag, "Encrypt") == 0)                 // Returns zero if strings match
        {
            ch_ptr = strchr(original_alphabet, input[i]);
            if(ch_ptr == NULL)
            {
                output[i] = input[i];
            } else
            {
                output[i] = substitution_alphabet[ch_ptr - original_alphabet];
            }
        } else if(strcmp(flag, "Decrypt") == 0)          // Returns zero if strings match
        {
            ch_ptr = strchr(substitution_alphabet, input[i]);
            if(ch_ptr == NULL)
            {
                output[i] = input[i];
            } else
            {
                output[i] = original_alphabet[ch_ptr - substitution_alphabet];
            }
        }
    }
    return output;
}

// Permutate each character in the input with a fixed binary value
char* permutate(const char* input)
{
    printf("\n****** Permutate *****\n");
    int input_len = strlen(input);
    char* temp = (char*)calloc(1, input_len);

    for(int i = 0; i < input_len; i++)
    {
        temp[i] = input[i];
        temp[i] ^= 'U';     // Bitwise XOR operation with binary value 0b01010101
    }

    return temp;
}

/* BELOW ONLY REQURIED FOR TESTING */

// A function to get user input
const char* get_input()
{
    printf("\n****** Input *****\n");
    return "Random string for testing";
}

int main()
{
    // Provide information
    printf("****** Size Of Data Types *****\n");
    printf("char size: %lld byte/s\n", sizeof(char));

    // Get user input
    const char* input = get_input();
    printf("Input: %s\n", input);

    // ENCRYPT
        // Substitution - Perform substitution while input is still a string
        const char* sub_input = substitute(input, "Encrypt");
        printf("Output as string: %s\n", sub_input);

        // Permutation
        char* output = permutate(sub_input);

        // Output as hex to avoid getting unexpected characters and ensure it can be read
        printf("Output as hex: ");
        for(int i = 0; i < strlen(output); i++)
        {
            printf("%x", (uint8_t)output[i]);
        }
        printf("\n");

    // DECRYPT
        // Permutation
        char* de_per_input = permutate(output);
        printf("Output as string: %s\n", de_per_input);

        // Substitution
        const char* plain_output = substitute(de_per_input, "Decrypt");
        printf("Original text: %s\n", plain_output);
}