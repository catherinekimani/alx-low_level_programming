#include <stdio.h>
#include <stdarg.h>
#include "variadic_functions.h"

/**
 * print_all - function that prints anything
 * @param...: A variable number of integers
 * @format: list of types of args passed to the func
 */
void print_all(const char *const format, ...)
{
	va_list print_all;

	int i = 0, len = 0;

	while (format[len])
		len++;

	va_start(print_all, format);

	while (i < len)
	{
		switch (format[i++])
		{
		case 'c':/*char*/
			printf("%c", va_arg(print_all, int));
			break;
		case 'i':/*integer*/
			printf("%d", va_arg(print_all, int));
			break;
		case 'f':/*float*/
			printf("%f", va_arg(print_all, double));
			break;
		case 's':/*string*/
		{
			char *str = va_arg(print_all, char *);

			if (str == NULL)
				printf("(nil)");
			else
				printf("%s", str);
			break;
		}
		}
		if (i < len)
			printf(", ");
	}

	printf("\n");

	va_end(print_all);
}
