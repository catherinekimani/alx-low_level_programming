#include "lists.h"

/**
 * listint_len - func that returns the no. of elems in a linkedlist.
 * @h: pointer to the head of the list
 * Return: number of nodes
 */

size_t listint_len(const listint_t *h)
{
	size_t num_nodes = 0;

	while (h)
	{
		num_nodes++;
		h = h->next;
	}
	return (num_nodes);
}
