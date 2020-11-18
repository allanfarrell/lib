#ifndef SHA256
#define SHA256

namespace sha256
{
    /**
     * Calculate the hash value using SHA-2 256 hashing algorithm
     * 
     * @param input    Value to be hashed as a char[]
     * @return         The hash value as a char[]
     */
    string hash(const char* input);
}

#endif