#include <stdio.h>
#include "main.h"
/**
 * _pow_recursion-  function that returns
 *  the value of x raised to the power of y.
 * @x: pointer to int
 * @y: pointer to int
 *
 * Return: -1 if y is lower than 0
 */
int _pow_recursion(int x, int y)
{
	if (y < 0)
	{
		return (-1);
	}
	else if (y == 0)
	{
		return (1);
	}
	else
	{
		return ((x) * _pow_recursion(x, y - 1));
	}
}
