#include "lists.h"

/**
 * add_dnodeint - func to add nodes at the beginning
 * @head: pointer
 * @n: element value
 *
 * Return: address of the new element
 *         or NULL if it fails
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *new_node;
	dlistint_t *current;

	new_node = malloc(sizeof(dlistint_t));
	if (new_node == NULL)
		return (NULL);
	new_node->n = n;
	new_node->prev = NULL;
	current = *head;

	if (current != NULL)
	{
		while (current->prev != NULL)
			current = current->prev;
	}
	new_node->next = current;
	if (current != NULL)
		current->prev = new_node;
	*head = new_node;
	return (new_node);
}
