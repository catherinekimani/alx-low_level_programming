#include "lists.h"

/**
 * pop_listint - func that deletes the head node of a list.
 * @head: pointer to the list
 *
 * Return: data (n) of the head node, or 0 if the list is empty.
 */

int pop_listint(listint_t **head)
{
	listint_t *current;
	int data;

	if (!head || !*head)
		return (0);

	data = (*head)->n;
	current = (*head)->next;
	free(*head);
	*head = current;

	return (data);
}
