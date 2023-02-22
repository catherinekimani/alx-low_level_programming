#include "main.h"
/**
 * times_table - function that prints the 9 times table, starting with 0.
 * Return: 0
 */
void times_table(void)
{
	int num1, num2, product;

	for (num1 = 0; num1 < 10; num1++)
	{
		for (num2 = 0; num2 < 10; num2++)
		{
			product = num1 * num2;
			if (num2 == 0)
			{
				_putchar(product + '0');
			}
			if (product < 10 && num2 != 0)
			{
				_putchar(',');
				_putchar(' ');
				_putchar(' ');
				_putchar(product + '0');
			}
			else if (product >= 10)
			{
				_putchar(',');
				_putchar(' ');
				_putchar((product / 10) + '0');
				_putchar((product % 10) + '0');
			}
		}
		 _putchar('\n');
	}
}
