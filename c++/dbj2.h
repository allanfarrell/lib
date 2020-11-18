#ifndef DBJ2
#define DBJ2

/**
 * ONLY OBJECTS/FUNCTIONS/PROCEDURES THAT ARE USED BY OTHER MODULES
 * ARE INCLUDED IN THE HEADER
 */

namespace dbj2
{
    /**
     * Convert string to hash using dbj2
     * 
     * @param       The value to hash
     * @return      The hashed value
     */
    unsigned long hash(string str);
}

#endif