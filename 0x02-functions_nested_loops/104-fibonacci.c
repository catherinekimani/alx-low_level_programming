#include <stdio.h>

/**
 * main - finds and prints the first 98 Fibonacci numbers,
 * starting with 1 and 2
 * followed by a new line
 * Return: ALways 0 (Success)
 */

int main(void)
{
	int a = 1, b = 2, count = 2, fib;

	printf("%d, %d, ", a, b);
	while (count < 98)
	{
		fib = a + b;
		printf("%d, ", fib);
		count++;
		a = b;
		b = fib;
	}
	printf("\n");
	return (0);
}
