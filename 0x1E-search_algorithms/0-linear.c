#include "search_algos.h"

/**
 * linear_search - func that searches for a value in an array of ints
 * @array: pointer to the first element of the array to search in
 * @size: number of elements in array
 * @value: the value to search for
 *
 * Return: If value is not present in array or if array is NULL return -1
 */

int linear_search(int *array, size_t size, int value)
{
	size_t idx = 0;

	if (array == NULL)
		return (-1);

	for (idx = 0; idx < size; idx++)
	{
		printf("Value checked array[%lu] = [%d]\n", idx, array[idx]);

		if (array[idx] == value)
			return (idx);
	}
	return (-1);
}
