#include <stdlib.h>
#include "main.h"
/**
 * array_range - creates an array of integers
 * @min: the minimum value
 * @max: the maximum value
 *
 * Return: ff min > max, returns NULL. Otherwise
 *         returns a pointer to the newly
 *         allocated array.
 */
int *array_range(int min, int max)
{
	void *allocated_mem;
	unsigned int alloc_size;
	int *array;
	unsigned int i;

	/*if min > max return NULL*/
	if (min > max)
		return (NULL);
	/*calculate size of mem*/
	alloc_size = (max - min + 1) * sizeof(int);
	allocated_mem = malloc(alloc_size);
	/*return NULL if malloc fails*/
	if (allocated_mem == NULL)
		return (NULL);
	array = (int *)allocated_mem;
	for (i = 0; i < (unsigned int)(max - min + 1); i++)
		array[i] = min + i;
	/* Return a pointer to the integer array */
	return (array);
}
