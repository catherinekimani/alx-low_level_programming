#include "main.h"
#include <stdio.h>
#include <string.h>
/**
 * _strncat -  function that concatenates two strings.
 * @dest: append string
 * @src: string from which ‘n’ characters are going to append
 * @n: number of characters to be appended
 * Return: a pointer
 */
char *_strncat(char *dest, char *src, int n)
{
	int i, src_idx;

	for (i = 0; dest[i] != '\0'; i++)
		;

	for (src_idx = 0; src[src_idx] != '\0' && n > 0; src_idx++, n--, i++)
	{
		dest[i] = src[src_idx];
	}
	return (dest);
}
