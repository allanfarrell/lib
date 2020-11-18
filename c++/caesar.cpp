#include <cstring>
#include <string>

using std::string;

// The number of letters the cipher will shift
#define SHIFT 12

namespace caesar
{
    // Encrypt plain text to ciphertext
    string encrypt(string plain_text)
    {
        string cipher_text = "";
        int length = plain_text.length();

        // Loop through plain text
        for (int i = 0; i < length; i++)
        {
            if (isalpha(plain_text[i]))
            {
                // Upper case characters
                if(isupper(plain_text[i]))
                {
                    if((int)plain_text[i] > 90 - SHIFT)
                    {
                        cipher_text += (int)plain_text[i] - 26 + SHIFT;
                    } else
                    {
                        cipher_text += (int)plain_text[i] + SHIFT;
                    }
                // Lower case characters
                } else
                {
                    if((int)plain_text[i] > 122 - SHIFT)
                    {
                        cipher_text += (int)plain_text[i] - 26 + SHIFT;
                    } else
                    {
                        cipher_text += (int)plain_text[i] + SHIFT;
                    }
                }
            }
            else
            {
                cipher_text += plain_text[i];
            }
        }
        return cipher_text;
    }

    // Decrypt ciphertext to plain text
    string decrypt(string cipher_text)
    {
        string plain_text = "";

        // Loop through plain text
        int length = cipher_text.length();
        for (int i = 0; i < length; i++)
        {
            if(isalpha(cipher_text[i]))
            {
                // Upper case characters
                if(isupper(cipher_text[i]))
                {
                    if((int)cipher_text[i] < 65 + SHIFT)
                    {
                        plain_text += (int)cipher_text[i] + 26 - SHIFT;
                    } else
                    {
                        plain_text += (int)cipher_text[i] - SHIFT;
                    }
                // Lower case characters
                } else
                {
                    if((int)cipher_text[i] < 97 + SHIFT)
                    {
                        plain_text += (int)cipher_text[i] + 26 - SHIFT;
                    } else
                    {
                        plain_text += (int)cipher_text[i] - SHIFT;
                    }
                }
            }
            else
            {
                plain_text += cipher_text[i];
            }
        }
        return plain_text;
    }
}