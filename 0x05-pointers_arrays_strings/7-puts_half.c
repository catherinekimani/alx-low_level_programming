# include "main.h"
#include <stdio.h>
#include <string.h>
/**
 * puts_half - function that prints half of a string,
 * followed by a new line.
 * @str: pointer to string
 */
void puts_half(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		i++;
	}
	for (i /= 2; str[i] != '\0'; i++)
	{
		_putchar(str[i]);
	}
	_putchar('\n');
}
