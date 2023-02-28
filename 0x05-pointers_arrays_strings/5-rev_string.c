# include "main.h"
# include <stdio.h>
# include <string.h>
/**
 * rev_string - function that reverses a string.
 * @s: Character to be checked
 * Return: 0
 */
void rev_string(char *s)
{
	int length = 0,  i = 0,  j = 0;
	char tmp;

	while (s[length] != '\0')
	{
		length++;
	}

	j  =  length - 1;
	while (i  <  j)
	{
		tmp  =  s[i];
		s[i]  =  s[j];
		s[j]  =  tmp;
		i++;
		j--;
	}
}
