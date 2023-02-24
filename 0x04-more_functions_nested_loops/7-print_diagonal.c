# include "main.h"
/**
 * print_diagonal - function that draws a diagonal line on the terminal.
 * @n: Character to be checked
 * Return: 0
 */
void print_diagonal(int n)
{
	int i;

	if (n <= 0 )
	{
		_putchar('\n');
		return;
	}
	for (i = 0; i < n; i++)
	{
		_putchar('\\');
	}
	_putchar('\n');
}
