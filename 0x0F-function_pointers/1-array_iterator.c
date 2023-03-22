#include <stdio.h>
#include "function_pointers.h"
/**
 * array_iterator - function that executes a function given
 * as a parameter on each element of an array
 * @array: pointer to the first element of an array of integers
 * @size: size of array
 * @action: a pointer to function
 */
void array_iterator(int *array, size_t size, void (*action)(int))
{
	size_t i = 0;

	if (array == NULL || action == NULL)
		return;
	while (i < size)
	{
		action(array[i]);
		i++;
	}
}
