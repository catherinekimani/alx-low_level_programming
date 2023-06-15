#include "lists.h"

/**
 * delete_dnodeint_at_index - func to delete a node
 * @head: pointer
 * @index: index of the node
 *
 * Return: 1 for SUCCESS
 *         -1 it it fails
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *current;
	unsigned int idx = 0;

	if (*head == NULL)
		return (-1);
	current = *head;

	if (index == 0)
	{
		*head = current->next;
		if (*head != NULL)
			(*head)->prev = NULL;
		free(current);
		return (-1);
	}
	while (current != NULL && idx < index)
	{
		current = current->next;
		idx++;
	}
	if (current == NULL)
		return (-1);
	if (current->next != NULL)
		current->next->prev = current->prev;
	if (current->prev != NULL)
		current->prev->next = current->next;
	free(current);
	return (1);
}
