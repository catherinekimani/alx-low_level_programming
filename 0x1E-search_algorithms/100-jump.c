#include "search_algos.h"

/**
 * jump_search -  func that searches for a value in a sorted array of ints
 *                using the Jump search algorithm
 * @array: pointer to the first element of the array to search in
 * @size: number of elements in array
 * @value: the value to search for
 *
 * Return: If value is not present in array or if array is NULL return -1
 */
int jump_search(int *array, size_t size, int value)
{
	size_t prev_idx, jump_step, idx;

	if (array == NULL || size == 0)
		return (-1);

	jump_step = sqrt(size);

	for (idx = prev_idx = 0; prev_idx < size && array[prev_idx] < value;)
	{
		printf("Value checked array[%ld] = [%d]\n", prev_idx, array[prev_idx]);
		idx = prev_idx;
		prev_idx += jump_step;
	}

	printf("Value found between indexex [%ld] and [%ld]\n", idx, prev_idx);

	prev_idx = prev_idx < size - 1 ? prev_idx : size - 1;

	for (; idx < prev_idx && array[idx] < value; idx++)
		printf("Value checked array[%ld] = [%d]\n", idx, array[idx]);

	printf("Value checked array[%ld] = [%d]\n", idx, array[idx]);

	return (array[idx] == value ? (int)idx : -1);
}
