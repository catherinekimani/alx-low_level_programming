# include "main.h"
#include <stdio.h>
#include <string.h>
/**
 * print_rev - function that prints a string,
 * in reverse, followed by a new line.
 * @s - Character to be checked
 * Return: 0
 */
void print_rev(char *s)
{
	int length = strlen(s);
	int a;

	for(a = length - 1;a >= 0; a--;)
	{
		printf("%c", s[i]);
	}
	printf("\n");
}
