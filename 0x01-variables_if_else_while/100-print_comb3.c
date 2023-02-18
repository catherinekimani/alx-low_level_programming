# include <stdio.h>
/**
 * main - entry point
 * print all possible combinations of two digits
 * Return: Always 0 (success)
 */
int main(void)
{
	int a, b;

	for (a = 0; a <= 8; a++)
	{
		for (b = a + 1; b <= 9; b++)
		{
			putchar('0' + a);
			putchar('0' + b);
			if (a != 8 || b != 9)
			{
				putchar(',');
				putchar(' ');
			}
		}
	}
	putchar('\n');
	return (0);
}
