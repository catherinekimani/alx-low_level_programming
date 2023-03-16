#include <stdlib.h>
#include "main.h"

/**
 * _realloc - reallocates a memory block using malloc and free
 * @ptr: pointer to the memory previously allocated with malloc
 * @old_size: size, in bytes, of the allocated space for ptr
 * @new_size: new size, in bytes, of the new memory block
 *
 * Return: pointer to the newly allocated memory block
 * or NULL if the allocation fails
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *new_mem_block, *old_ptr;
	unsigned int i;

	/* if new size is the same as old size,return the old pointer */
	if (new_size == old_size)
		return (ptr);

	/* if old pointer is NULL, allocate New block */
	if (ptr == NULL)
		return (malloc(new_size));

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	/* allocate a new block using malloc */
	new_mem_block = malloc(new_size);
	/* if malloc fails return NULL */
	if (new_mem_block == NULL)
		return (NULL);

	/*Copy the contents of the old mem block to the new mem block */
	old_ptr = ptr;
	for (i = 0; i < old_size && i < new_size; i++)
		new_mem_block[i] = old_ptr[i];

	/* free the old block*/
	free(ptr);

	/* return the pointer to the new block */
	return (new_mem_block);
}
