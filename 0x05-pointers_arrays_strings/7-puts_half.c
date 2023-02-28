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
	int length = strlen(str);
	int start_index = length / 2;
	int i;

	if (length % 2 == 1)
	{
		start_index = (length - 1) / 2;
	}
	for (i = start_index; i < length; i++)
	{
		printf("%c", str[1]);
	}
	 printf("\n");
}
