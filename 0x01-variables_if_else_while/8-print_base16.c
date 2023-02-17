# include <stdio.h>
/**
 * main - entry point
 * print numbers of base 16
 * Return: Always 0 (success)
 */
int main(void)
{
	int i;

	for (i = 0; i < 10; i++)
	{
		putchar(i + '0');
	}
	for (i = 0; i < 6; i++)
	{
		putchar(i + 'a');
	}
	putchar('\n');
	return (0);
}
