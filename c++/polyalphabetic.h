#ifndef POLYALPHABETIC
#define POLYALPHABETIC

namespace polyalphabetic
{
    /**
     * Encrypt input using variation of the Vignere cipher
     * 
     * @param input The value to encrypt as a char[]
     * @return      The encrypted output as a char[]
     */
    char* encrypt(const char* input);

    /**
     * Decrypt using a variation of the Vignere cipher
     * 
     * @param input The value to decrypt as a char[]
     * @return      The decrypted output as a char[]
     */
    char* decrypt(const char* input);
}

#endif