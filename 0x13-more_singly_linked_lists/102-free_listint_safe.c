#include "lists.h"

/**
 * free_listint_safe - func that free a list
 * @h: pointer to the head of the list
 *
 * Return: no. of nodes freed in the list
 */

size_t free_listint_safe(listint_t **h)
{
	size_t num_nodes = 0;
	listint_t *current_node;

	if (!h)
		return (num_nodes);

	while (*h && *h > (*h)->next)
	{
		current_node = *h;
		*h = (*h)->next;
		free(current_node);
		num_nodes++;
	}

	if (!h)
	{
		free(*h);
		*h = NULL;
		num_nodes++;
	}
	return (num_nodes);
}
