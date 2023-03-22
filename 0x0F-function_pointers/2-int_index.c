#include <stdio.h>
#include "function_pointers.h"
/**
 * int_index - function that searches for an integer
 * @size: number of elements in the array
 * @cmp: a pointer to function
 * @array: pointer to the first element of an array of integers
 * Return: int_index returns the index of the first element for
 * which the cmp function does not return 0
 * If no element matches, return -1
 *         If size <= 0, return -1
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int i = 0;

	if (array == NULL || cmp == NULL || size <= 0)
		return (-1);
	while (i < size)
	{
		if (cmp(array[i]))
			return (i);
		i++;
	}
	return (-1);
}
