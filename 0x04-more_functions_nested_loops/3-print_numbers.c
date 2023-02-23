#include "main.h"
/**
 * print_numbers - function that prints the numbers,
 * from 0 to 9, followed by a new line.
 * Return: 0
 */
void print_numbers(void)
{
	int c = 0;

	while (c < 10)
	{
		_putchar(c + '0');
		c++;
	}
	_putchar('\n');
}
