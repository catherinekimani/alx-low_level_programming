#include "lists.h"

/**
 * get_dnodeint_at_index - Create func to return nth node
 * @head: pointer
 * @index: index of the node from 0
 *
 * Return: nth node
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int idx;

	if (head == NULL)
		return (NULL);
	idx = 0;
	while (head != NULL)
	{
		if (idx == index)
			break;
		head = head->next;
		idx++;
	}
	return (head);
}
