#include <stdio.h>
#include "main.h"
/**
 * factorial - function that returns the factorial of a given number.
 * @n: pointer to int
 *
 * Return: the factorial of given number
 */
int factorial(int n)
{
	if (n < 0)
	{
		return (-1);
	}
	else if (n == 0)
	{
		return (1);
	}
	else
	{
		return ((n) * factorial(n - 1));
	}
}
