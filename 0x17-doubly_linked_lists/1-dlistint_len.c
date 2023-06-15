#include "lists.h"

/**
 * dlistint_len - return number of elements in a list
 * @h: pointer
 *
 * Return: Number of nodes
 */
size_t dlistint_len(const dlistint_t *h)
{
	int num_nodes;

	num_nodes = 0;

	if (h == NULL)
		return (num_nodes);
	while (h->prev != NULL)
		h = h->next;
	while (h != NULL)
	{
		num_nodes++;
		h = h->next;
	}
	return (num_nodes);
}
