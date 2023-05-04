#include "main.h"

/**
 * get_endianness - func that checks for endianness
 *
 * endianness is basically a way in which a computer
 * stores multiple data types in memory
 *
 * Return: 0 if big endian
 *         1 if little endian
 */

int get_endianness(void)
{
	int number = 1;
	char *ptr = (char *)&number;

	if (*ptr == 1)
		return (1);

	return (0);
}
