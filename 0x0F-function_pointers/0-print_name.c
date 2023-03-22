#include <stdio.h>
#include "function_pointers.h"
/**
 * print_name - function that prints a name
 * @f:a pointer to function
 * @name: character
 * Return: 0
 */

void print_name(char *name, void (*f)(char *))
{
	(*f)(name);
}
