#include <stdio.h>
#include <stdarg.h>
#include "variadic_functions.h"
/**
 *  print_strings - function that prints strings, followed by a new line
 * @n: number of integers to sum
 * @separator: string to be printed between numbers
 * @param...: A variable number of integers to sum
 *
 */
void print_strings(const char *separator, const unsigned int n, ...)
{
	unsigned int i;

	char *str;

	va_list mystr;

	va_start(mystr, n);

	for (i = 0; i < n; i++)
	{
		str = va_arg(mystr, char*);
		if (str == NULL)
			printf("(nil)");
		else
			printf("%s", str);

		if (separator != NULL && i != n - 1)
			printf("%s", separator);
	}
	va_end(mystr);
	printf("\n");
}
