#include "main.h"
/**
 * print_sign - Prints the sign of a given integer
 * @n: the integer to be checked
 *
 * Return: 1 and prints + if n is greater than zero
 *         0 and prints 0 if n is zero
 *        -1 and prints - if n is less than zero
 */
int print_sign(int n)
{
	if (n > 0)
	{
		_putchar('+');
		_putchar('\n');
		return (1);
	}
	else if (n == 0)
	{
		_putchar('0');
		_putchar('\n');
		return (0);
	}
	else if (n < 0)
	{
		_putchar('-');
		_putchar('\n');
		return (-1);
	}
	return (0);
}
