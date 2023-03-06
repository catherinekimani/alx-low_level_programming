#include "main.h"
/**
 * _strpbrk - function that searches a string for any of a set of bytes.
 * @s: string to be searched
 * @accept:  C string containing the characters to match.
 * Return:  pointer to the byte in s
 */
char *_strpbrk(char *s, char *accept)
{
	int i, j;
	char *p;

	i = 0;
	while (s[i] != '\0')
	{
		j = 0;
		while (accept[j] != '\0')
		{
			if (accept[j] == s[i])
			{
				p = &s[i];
				return (p);
			}
			j++;
		}
		i++;
	}

	return (0);
}
