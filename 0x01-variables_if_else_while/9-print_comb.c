# include <stdio.h>
/**
 * main - entry point
 * program prints all possible combinations of single digi numbers
 * Return: Always 0 (success)
 */
int main(void)
{
	int num;

	for (num = 0; num < 10; num++)
	{
		putchar(num + '0');
		if (num != 9)
		{
			putchar(',');
			putchar(' ');
		}
	}
	putchar('\n');
	return (0);
}
