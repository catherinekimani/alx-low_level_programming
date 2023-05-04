#include <stdio.h>
#include "main.h"

/**
 * binary_to_uint - converts a binary number to an unsigned int
 * @b: pointer to string of 0 and 1 chars
 *
 * Return: Converted or 0 if there is no more chars
 *         in the string b that is not 0 or 1 0r if b is NULL
 */

unsigned int binary_to_uint(const char *b)
{
	unsigned int num = 0;
	int str_length = 0;

	if (b == NULL)
		return (0);

	if (b[str_length] == '\0')
		return (0);

	while ((b[str_length] == '0') || (b[str_length] == '1'))
	{
		num <<= 1;
		num += b[str_length] - '0';
		str_length++;
		if (b[str_length] == '\0')
			break;
		if (b[str_length] != '0' && b[str_length] != '1')
			return (0);
	}
	return (num);
}
