# include "main.h"
/**
 * print_square - function that prints a square, followed by a new line.
 * @size: charcter to be checked
 * Retrn: 0
 */
void print_square(int size)
{
	int a, b;

	if (size <= 0)
	{
		_putchar('\n');
		return;
	}
	for (a = 0; a < size; a++)
	{
		for (b = 0; b < size; b++)
		{
			_putchar('#');
		}
		_putchar('\n');
	}
}
