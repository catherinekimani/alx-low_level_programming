#include "lists.h"

/**
 * sum_listint - func that returns the sum of all the data (n) of a list.
 * @head: pointer to the head of te list
 *
 * Return: Sum of all data or 0 if list is empty
 */

int sum_listint(listint_t *head)
{
	int sum = 0;

	while (head != NULL)
	{
		sum += head->n;
		head = head->next;
	}
	return (sum);
}
