#include "lists.h"

/**
 * add_nodeint_end -  func that adds a new node at the end of a list.
 * @head: pointer the first node.
 * @n: value to be added to new node
 * Return: the address of the new element, or NULL if it failed
 */

listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *new_node;
	listint_t *current = *head;

	new_node = malloc(sizeof(listint_t));

	if (new_node == NULL)
		return (NULL);

	new_node->n = n;
	new_node->next = NULL;

	if (*head == NULL)
	{
		*head = new_node;
		return (new_node);
	}

	while (current->next)
		current = current->next;

	current->next = new_node;

	return (new_node);
}
