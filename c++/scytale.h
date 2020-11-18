#ifndef SCYTALE
#define SCYTALE

namespace scytale
{
    /**
     * Encrypt and Decrypt input using scytale cipher
     * 
     * @param input The value to encrypt/decrypt as a char[]
     * @param key   The number of columns to be used
     * @return      The processed input as a char[] - plaintext / ciphertext
     */
    char* scytale(char* input, int key);
}

#endif