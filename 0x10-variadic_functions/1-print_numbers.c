#include <stdio.h>
#include <stdarg.h>
#include "variadic_functions.h"
/**
 * print_numbers - function that prints numbers
 * @separator: string to be printed between numbers
 * @param...: A variable number of integers to sum
 *@n: number of integers
 */
void print_numbers(const char *separator, const unsigned int n, ...)
{
	unsigned int i, num;

	va_list mynums;

	va_start(mynums, n);

	for (i = 0; i < n; i++)
	{
		num = va_arg(mynums, int);
		printf("%d", num);

		if (i < n - 1 && separator != NULL)
		{
			printf("%s", separator);
		}
	}

	va_end(mynums);
	printf("\n");
}
