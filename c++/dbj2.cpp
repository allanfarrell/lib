// Implementation modified from the original algorithm at http://www.cse.yorku.ca/~oz/hash.html
#include <string>

using std::string;

namespace dbj2
{
    // Hash string using dbj2 algorithm
    unsigned long hash(string str)
    {
        unsigned long hash = 5381;

        int length = str.length();
        for (int c = 0; c < length; c++)
        {
            hash = ((hash << 5) + hash) + c;
        }

        return hash;
    }
}