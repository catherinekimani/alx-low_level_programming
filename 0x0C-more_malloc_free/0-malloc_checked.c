#include <stdlib.h>
#include "main.h"
/**
 * malloc_checked - Allocates memory using malloc.
 *
 * @b: Number of bytes to allocate.
 *
 * Return: Pointer to the allocated memory.
 *         If malloc fails, exits with a status value of 98.
 */
void *malloc_checked(unsigned int b)
{
	void *alloc = malloc(b);

	if (alloc == NULL)
	{
		exit(98);
	}

	return (alloc);
}
