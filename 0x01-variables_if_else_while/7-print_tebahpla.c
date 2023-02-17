# include <stdio.h>
/**
 * main -entry point
 * program that prints alphabets in lowercase & in reverse
 * Return: Always 0 (Success)
 */
int main(void)
{
	char letter = 'a';

	while (letter <= 'z')
	{
		putchar('z' - (letter - 'a'));
		letter++;
	}
	putchar ('\n');
	return (0);
}
