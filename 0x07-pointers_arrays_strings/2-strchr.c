#include "main.h"
#include <stddef.h>
/**
 * _strchr - function that locates a character in astring
 * @s: string to be checked
 * @c: character to be searched
 * Return: pointer
 */
char *_strchr(char *s, char c)
{
	while (*s != '\0')
	{
		if (*s == c)
		{
			return (s);
		}
		s++;
	}
	if (c == '\0')
	{
		return (s);
	}
	return (NULL);
}
