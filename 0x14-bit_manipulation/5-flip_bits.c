#include "main.h"

/**
 * flip_bits - func that returns the no. of bits you would
 *             need to flip to get from one no. to another.
 * @n: first no.
 * @m: second no.
 *
 * Return: Required no. of bits
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int bits = 0;
	unsigned long int xor_res = n ^ m;

	while (xor_res > 0)
	{
		bits += (xor_res & 1);
		xor_res >>= 1;
	}
	return (bits);
}
