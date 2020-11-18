#ifndef CAESAR
#define CAESAR

/**
 * ONLY OBJECTS/FUNCTIONS/PROCEDURES THAT ARE USED BY OTHER MODULES
 * ARE INCLUDED IN THE HEADER
 */

namespace caesar
{
    /**
     * Encrypt plain text to cipher text using substitution.
     * Only encrypts alphabetical characters
     * 
     * @param       The text to encrypt
     * @retrun      The encrypted text
     */
    string encrypt(string plain_text);

    /**
     * Decrypt cipher text to plain text via substitution.
     * 
     * @param       The text to decrypt
     * @retrun      The decrypted text
     */
    string decrypt(string cipher_text);
}

#endif