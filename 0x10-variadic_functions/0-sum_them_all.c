#include <stdio.h>
#include <stdarg.h>
#include "variadic_functions.h"
/**
 *  sum_them_all - func that returns the sum of all its parameters
 * @n: number of integers to sum
 * @param...: A variable number of integers to sum.
 * Return: if n == 0; return 0
 */
int sum_them_all(const unsigned int n, ...)
{
	unsigned int i = 0, sum = 0;

	va_list sum_all;

	va_start(sum_all, n);

	if (n == 0)
		return (0);
	while (i < n)
	{
		sum = sum + va_arg(sum_all, unsigned int);
		i++;
	}
	va_end(sum_all);
	return (sum);
}
