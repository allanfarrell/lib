#include <stdio.h>      // printf
#include <string.h>     // strlen, strcmp
#include <stdlib.h>     // calloc

namespace scytale
{
    // Scytale transposition cipher
    char* scytale(char* input, int key) {
        char* output = (char*)calloc(1, strlen(input)+1);
        int length = strlen(input);
        
        // Loop through each column - the number of columns is equal to the key
        for(int c = 0; c < key; c++) {

            // Loop through all values in a row
            for(int r = c; r < length; r += key) {
                output[strlen(output)] = input[r];
            }
        }
        return output;
    }
}