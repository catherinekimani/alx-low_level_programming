#include <stdlib.h>
#include "main.h"

/**
 * _realloc - Reallocates a memory block using malloc and free
 * @ptr: Pointer to the memory previously allocated with a call to malloc
 * @old_size: Size, in bytes, of the allocated space for ptr
 * @new_size: New size, in bytes, of the new memory block
 *
 * Return: Pointer to the reallocated memory block
 *         NULL if new_size is 0 and ptr is not NULL
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	unsigned int i;
	void *new_memory_block;
	char *p;
	char *new_p;
	/* If new_size is 0, free ptr and return NULL */
	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	/* If ptr is NULL, equivalent to malloc(new_size) */
	if (ptr == NULL)
	{
		return (malloc(new_size));
	}
	/* If new_size and old_size are the same, do nothing and return ptr */
	if (new_size == old_size)
	{
		return (ptr);
	}
	/* Allocate new mem block of new_size */
	new_memory_block = malloc(new_size);
	if (new_memory_block == NULL)
	{
		/* If malloc fails, return NULL */
		return (NULL);
	}
	/* Copy the contents of the old mem block to the new mem block */
	p = ptr;
	new_p = new_memory_block;
	for (i = 0; i < old_size && i < new_size; i++)
	{
		new_p[i] = p[i];
	}
	/* Free the old mem block */
	free(ptr);
	/* Return pointer to the new mem block */
	return (new_memory_block);
}
