#include "main.h"
/**
 * print_triangle - function that prints a triangle,
 * followed by a new line.
 * @size: character to be checked
 * Return: 0
 */
void print_triangle(int size)
{
	int i, j;

	if (size <= 0)
	{
		_putchar('\n');
		return;
	}
	for (i = 0; i < size; i++)
	{
		for (j = 0; j <= i; j++)
		{
			_putchar('#');
		}
		_putchar('\n');
	}
}
