#include "lists.h"

/**
 * free_dlistint - func to free a doubly linked list
 * @head: pointer
 *
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *current;

	while (head != NULL)
	{
		current = head;
		head = head->next;
		free(current);
	}
}
