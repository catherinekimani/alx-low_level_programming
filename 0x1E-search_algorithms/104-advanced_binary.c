#include "search_algos.h"

int advanced_binary_recursive(
	int *array, size_t left, size_t right, int value);

/**
 * advanced_binary_recursive - performs recursive binary search
 * @array: ptr to the first element
 * @right: start index
 * @left: end index
 * @value: value to search for
 *
 * Return: -1 || index where value is located
 */

int advanced_binary_recursive(int *array, size_t left, size_t right, int value)
{
	size_t idx;

	if (right < left)
		return (-1);

	printf("Searching in array: ");
	for (idx = left; idx < right; idx++)
		printf("%d, ", array[idx]);
	printf("%d\n", array[idx]);

	idx = left + (right - left) / 2;
	if (array[idx] == value && (idx == left || array[idx - 1] != value))
		return (idx);

	if (array[idx] >= value)
		return (advanced_binary_recursive(array, left, idx, value));

	return (advanced_binary_recursive(array, idx + 1, right, value));
}

/**
 * advanced_binary - func that searches for a value in a sorted array of ints.
 * @array: pointer to the first element of the array
 * @size: number of elements in array
 * @value: value to search for
 *
 * Return: If value is not present in array or if array is NULL, return -1
 */

int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL || size == 0)
		return (-1);

	return (advanced_binary_recursive(array, 0, size - 1, value));
}
