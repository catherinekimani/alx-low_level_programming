#include "main.h"
/**
 * main - entry point
 * _isalpha -  Return 1 if c letter is a letter, 0 if not.
 * @c: char type letter
 * Return: 1 if letter, 0 if not
 */
int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
