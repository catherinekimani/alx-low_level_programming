#include <stdlib.h>
#include "main.h"
/**
 * _calloc - Allocates memory for an array & initializes it to 0
 *
 * @nmemb: Number of elements to allocate
 * @size: Size of each element
 *
 * Return: pointer to the allocated memory, or NULL if allocation fails
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	void *allocated_mem;
	char *char_ptr;
	unsigned int i;
	/* Calculate amount of mem */
	unsigned int alloc_size = nmemb * size;

	/* If nmemb or size is 0, return NULL */
	if (nmemb == 0 || size == 0)
		return (NULL);

	/* Allocate mem using malloc */
	allocated_mem = malloc(alloc_size);

	/* If malloc fails, return NULL */
	if (allocated_mem == NULL)
		return (NULL);

	/* Set the allocated mem to zero*/
	char_ptr = (char *)allocated_mem;
	for (i = 0; i < alloc_size; i++)
		char_ptr[i] = 0;

	/* Return the pointer to the allocated mem */
	return (allocated_mem);
}
