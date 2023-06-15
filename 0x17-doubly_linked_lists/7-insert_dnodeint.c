#include "lists.h"

/**
 * insert_dnodeint_at_index - func to insert new node
 * @h: pointer
 * @idx: index of the list
 * @n: value of the node
 *
 * Return: address of new, NULL if it fails
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new_node;
	dlistint_t *current = *h;
	unsigned int indx;

	if (h == NULL)
		return (NULL);
	new_node = malloc(sizeof(dlistint_t));
	if (new_node == NULL)
		return (NULL);
	new_node->n = n;
	new_node->prev = NULL;
	new_node->prev = NULL;

	if (idx == 0)
	{
		if (*h != NULL)
			(*h)->prev = new_node;
		new_node->next = *h;
		*h = new_node;
	}
	while (indx < idx - 1)
	{
		if (current == NULL)
			return (NULL);
		current = current->next;
		indx++;
	}
	if (current == NULL)
		return (NULL);
	new_node->next = current->next;
	new_node->prev = current;
	if (current->next == new_node)
		current->next->prev = new_node;
	current->next = new_node;
	return (new_node);
}
