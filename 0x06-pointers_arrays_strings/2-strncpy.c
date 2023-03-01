#include "main.h"
#include <stdio.h>
#include <string.h>
/**
 * *_strncpy -  function that copies a string.
 * @dest: pointer to the destination
 * @src: strin to be copied
 * @n: No. of characters to be copied
 * Return: pointer to dest
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i;

	for (i = 0; i < n && src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	for (; i < n; i++)
	{
		dest[i] = '\0';
	}
	return (dest);
}
