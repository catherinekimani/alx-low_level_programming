#include "lists.h"

/**
 * free_listint2 -  function that frees a listint_t list
 * @head: pointer to the head of the linked list
 */

void free_listint2(listint_t **head)
{
	listint_t *current;

	if (head == NULL)
		return;

	while (*head)
	{
		current = (*head)->next;
		free(*head);
		*head = current;
	}
	*head = NULL;
}
