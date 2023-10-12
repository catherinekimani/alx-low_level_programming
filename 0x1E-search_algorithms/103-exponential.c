#include "search_algos.h"
/**
 * _binary_search - func that searches for a value in a sorted array of ints
 * @array: pointer to the first element of the array to search in
 * @value: the value to search for
 * @left: left elem
 * @right: right elem
 *
 * Return: If value is not present in array or if array is NULL return -1
 */

int _binary_search(int *array, size_t left, size_t right, int value)
{
	size_t idx;

	if (array == NULL)
		return (-1);

	while (right >= left)
	{
		printf("Searching in array: ");
		for (idx = left; idx < right; idx++)
			printf("%d, ", array[idx]);
		printf("%d\n", array[idx]);

		idx = left + (right - left) / 2;
		if (array[idx] == value)
			return (idx);
		if (array[idx] > value)
			right = idx - 1;
		else
			left = idx + 1;
	}

	return (-1);
}

/**
 * exponential_search - function that searches for a value in a sorted array
 *                      of ints using the Exponential search algorithm
 * @array: pointer to the first element of the array to search in
 * @size: number of elements in array
 * @value: the value to search for
 *
 * Return: If value is not present in array or if array is NULL return -1
 */
int exponential_search(int *array, size_t size, int value)
{
	size_t i = 0;
	size_t right;

	if (array == NULL || size == 0)
		return (-1);
	if (array[0] != value)
	{
		for (i = 1; i < size && array[i] <= value; i *= 2)
			printf("Value checked array[%ld] = [%d]\n", i, array[i]);
	}

	right = i < size ? i : size - 1;
	printf("Value found between indexes [%ld] and [%ld]\n", i / 2, right);
	return (_binary_search(array, i / 2, right, value));
}
