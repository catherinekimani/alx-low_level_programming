#include "lists.h"
/**
 * list_len -  func that returns the no.of elms in a linkedlist
 * @h: singly linked list.
 * Return: number of elements in the list.
 */

size_t list_len(const list_t *h)
{
	size_t num_nodes;

	num_nodes = 0;

	while (h != NULL)
	{
		h = h->next;
		num_nodes++;
	}
	return (num_nodes);
}
