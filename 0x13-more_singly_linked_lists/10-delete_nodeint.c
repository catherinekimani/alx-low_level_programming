#include "lists.h"

/**
 * delete_nodeint_at_index - function that deletes node at
 *                           index of a linked list
 * @head : pointer to the head of the list
 * @index: index of the node to be deleted
 *         (starting at 0)
 * Return: 1 - if function succeeds,
 *        -1 - if function fails
 */

int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *temp, *current = *head;
	unsigned int node;

	if (current == NULL)
		return (-1);

	if (index == 0)
	{
		*head = (*head)->next;
		free(current);
		return (1);
	}
	for (node = 0; node < (index - 1); node++)
	{
		if (current->next == NULL)
			return (-1);

		current = current->next;
	}

	temp = current->next;
	current->next = temp->next;
	free(temp);
	return (1);
}
