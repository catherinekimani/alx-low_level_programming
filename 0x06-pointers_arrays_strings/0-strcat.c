#include "main.h"
#include <stdio.h>
#include <string.h>
/**
 * _strcat - function appends the src string to the dest string
 * @dest: pointer to character
 * @src: pointer to charcter
 * Return: a pointer
 */
char *_strcat(char *dest, char *src)
{
	int i, src_index;

	for (i = 0; dest[i] != '\0'; i++)
		;

	for (src_index = 0; src[src_index] != '\0'; src_index++)
	{
		dest[i] = src[src_index];
		i++;
	}

	dest[i] = '\0';
	return (dest);
}
