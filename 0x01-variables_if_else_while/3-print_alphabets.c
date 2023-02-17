#include <stdio.h>
/**
 * main - Entry point
 * print alphabets in lowercase and uppercase
 * Return: Always 0 (Success)
 */
int main(void)
{
	char letter_low = 'a';

	char letter_cap = 'A';

	while (letter_low <= 'z')
	{
		putchar(letter_low);
		letter_low++;
	}

	while (letter_cap <= 'Z')
	{
		putchar(letter_cap);
		letter_cap++;
	}
	putchar ('\n');
	return (0);
}
