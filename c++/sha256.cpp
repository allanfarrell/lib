#include <vector>
#include <string>
#include <cstring>

using std::string;
using std::vector;

namespace sha256
{
	/* ********** LOGICAL OPERATIONS ********** */

	unsigned long ROTRIGHT(unsigned long word, int bits)
	{
		return ((word >> bits) | (word << (32 - bits)));
	}

	unsigned long SSIG0(unsigned long x)
	{
		return (ROTRIGHT(x,7) ^ ROTRIGHT(x,18) ^ ((x) >> 3));
	}

	unsigned long SSIG1(unsigned long x)
	{
		return (ROTRIGHT(x,17) ^ ROTRIGHT(x,19) ^ ((x) >> 10));
	}

	unsigned long BSIG0(unsigned long x)
	{
		return (ROTRIGHT(x,2) ^ ROTRIGHT(x,13) ^ ROTRIGHT(x,22));
	}

	unsigned long BSIG1(unsigned long x)
	{
		return (ROTRIGHT(x,6) ^ ROTRIGHT(x,11) ^ ROTRIGHT(x,25));
	}

	unsigned long CH(unsigned long x, unsigned long y, unsigned long z)
	{
		return (((x) & (y)) ^ (~(x) & (z)));
	}

	unsigned long MAJ(unsigned long x, unsigned long y, unsigned long z)
	{
		return (((x) & (y)) ^ ((x) & (z)) ^ ((y) & (z)));
	}

	// Condense blocks into 16 * 32 bit blocks
	vector<unsigned long> condense_blocks(vector<unsigned long> input)
	{
		vector<unsigned long> output(16);

		// Loop through all of the blocks and condense
		for(int i = 0; i < 64; i = i + 4)
		{
			unsigned long temp;

			// Concatenate bits in blocks
			temp = (unsigned long) input[i] << 24;
			temp |= (unsigned long) input[i + 1] << 16;
			temp |= (unsigned long) input[i + 2] << 8;
			temp |= (unsigned long) input[i + 3];

			// Add the condensed block to the output vector
			output[i/4] = temp;
		}

		return output;
	}

	// Convert characters to 16 bit unsigned number
	vector<unsigned long> split_into_blocks(const string &input)
	{
		vector<unsigned long> block;

		// Convert each char into a format that can be easily manipulated
		for (int i = 0; i < input.size(); ++i)
		{
			unsigned long value = input.c_str()[i];
			block.push_back(value);
		}

		return block;
	}

	// Pad block to be 512 bits in total
	vector<unsigned long> pad_blocks(vector<unsigned long> block)
	{
		// Length of the input in bits - Each block only contains 8 bits
		int len = block.size() * 8;
		
		// Padding counter
		int k = 447 - len;

		// Add seperator to blocks vector
		unsigned long t1 = 0x80;
		block.push_back(t1);

		// Update padding counter
		k -= 7;

		// Add 8 bit blocks containing zero's
		for(int i = 0; i < k / 8; i++)
		{
			block.push_back(0x00000000);
		}
		
		// Convert the length of the input into a block
		unsigned long len_block = (unsigned long)len;

		// Add padding to the block vector
		for(int i = 0; i < 8; i++)
		{
			if(i < 7)
				block.push_back(0x00000000);
			if(i == 7)
				block.push_back(len_block);
		}

		return block;
	}

	// SHA256 hash calculations
	string hash_processing(const vector<unsigned long> block)
	{
		// Constants - First bits of the cubic roots of the fist 64 prime numbers
		const unsigned long k[64] = {0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
									0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3, 0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
									0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc, 0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
									0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7, 0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
									0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13, 0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
									0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3, 0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
									0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5, 0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
									0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208, 0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2};

		// Initial values - First bits of the square roots of the first 8 prime numbers
		unsigned long H[8] = {0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a, 0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19};

		unsigned long W[64];

		// Populate the first 16 places with values
		for(int t = 0; t <= 15; t++)
		{
			W[t] = block[t];
		}

		// Populate the rest of the places as per the spec
		for(int t = 16; t <= 63; t++)
		{
			W[t] = SSIG1(W[t-2]) + W[t-7] + SSIG0(W[t-15]) + W[t-16];
		}

		unsigned long temp1;
		unsigned long temp2;
		unsigned long a = H[0];
		unsigned long b = H[1];
		unsigned long c = H[2];
		unsigned long d = H[3];
		unsigned long e = H[4];
		unsigned long f = H[5];
		unsigned long g = H[6];
		unsigned long h = H[7];

		// Perform 64 rounds of obfuscation
		for( int t = 0; t < 64; t++)
		{
			temp1 = h + BSIG1(e) + CH(e,f,g) + k[t] + W[t];
			temp2 = BSIG0(a) + MAJ(a,b,c);

			h = g;
			g = f;
			f = e;
			e = (d + temp1); // Makes sure that we are still using 32 bits.
			d = c;
			c = b;
			b = a;
			a = (temp1 + temp2); // Makes sure that we are still using 32 bits.
		}

		// Merge final result into initial values
		H[0] = (H[0] + a);
		H[1] = (H[1] + b);
		H[2] = (H[2] + c);
		H[3] = (H[3] + d);
		H[4] = (H[4] + e);
		H[5] = (H[5] + f);
		H[6] = (H[6] + g);
		H[7] = (H[7] + h);

		char hash[256] = {0};
		char temp[16];

		// Convert to character array
		for(int i = 0; i < 8; i++)
		{
			sprintf(temp, "%lx", H[i]);
			strcat(hash, temp);
		}

		return hash;
	}

	// Main hash function the controls the steps
	// Currently does not support input larger than 447 bits - Needs to be extended
	string hash(const char* input)
	{
		vector<unsigned long> block;

		// Pre-processing
		block = split_into_blocks(input);
		block = pad_blocks(block);
		block = condense_blocks(block);

		// Hash processing
		string hash = hash_processing(block);

		return hash;
	}
}