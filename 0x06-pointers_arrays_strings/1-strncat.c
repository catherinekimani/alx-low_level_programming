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
	return ((strncat(dest, src, n)));
}
