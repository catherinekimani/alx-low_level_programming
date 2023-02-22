#include <stdio.h>

/**
 * main - Prints the sum of Even Fibonacci numbers
 * less than 4000000.
 *
 * Return: 0
 */
int main(void)
{
	int a = 1, b = 2, sum = 0, next;

	while (b <= 4000000)
	{
		if (b % 2 == 0)
			sum += b;
		next = a + b;

		a = b;
		b = next;
	}
	printf("%d\n", sum);
	return (0);
}
