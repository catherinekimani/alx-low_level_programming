#include "lists.h"

/**
 * sum_dlistint - func to return sum
 * @head: pointer
 *
 * Return: 0 if empty
 */
int sum_dlistint(dlistint_t *head)
{
	int sum;

	sum = 0;
	if (head == NULL)
		return (0);
	while (head != NULL)
	{
		sum += head->n;
		head = head->next;
	}
	return (sum);
}
