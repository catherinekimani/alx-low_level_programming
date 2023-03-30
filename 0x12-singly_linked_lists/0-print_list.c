#include "lists.h"

/**
 * print_list - function that prints all the elements of a list_t list
 * @h: Head of the list
 *
 * Return: The number of nodes
 */

size_t print_list(const list_t *h)
{
	size_t count = 0;

	const list_t *next = h;

	while (next != NULL)
	{
		if (next->str == NULL)
		{
			printf("[0] (nil)");
		}
		else
		{
			printf("[%d] %s\n", next->len, next->str);
		}
		count++;
		next = next->next;
	}
	return (count);
}
