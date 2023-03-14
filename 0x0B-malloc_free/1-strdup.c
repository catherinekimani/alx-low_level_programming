#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * _strdup -function that returns a pointer to
 * a newly allocated space in memory which
 * contains a copy of the string given as a parameter.
 * @str: string to duplicate
 *
 * Return: a pointer to the newly allocated memory, or NULL if
 * str is NULL or if insufficient memory was available.
 */
char *_strdup(char *str)
{
	char *dup_str;
	unsigned int len = 0, i = 0;

	if (str == NULL)
	{
		return (NULL);
	}
	while (str[len] != '\0')
		len++;
	dup_str = malloc(len + 1);
	if (dup_str == NULL)
		return (NULL);
	while (i <= len)
	{
		dup_str[i] = str[i];
		i++;
	}
	return (dup_str);
}
