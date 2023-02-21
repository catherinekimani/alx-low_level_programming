# include "main.h"
/**
 * print_alphabet - Print alphabet in lowercase using only `_putchar`
 * Return: 0
 */
void print_alphabet(void)
{
	char alphabets = 'a';

	while (alphabets <= 'z')
	{
		_putchar(alphabets);
		alphabets++;
	}
	_putchar('\n');
}
