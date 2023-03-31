#include "lists.h"

/**
 * free_list - unction that frees a list_t list
 * @head: head of the linked list.
 * Return: 0
 */
void free_list(list_t *head)
{
	list_t *current_node;

	while (head != NULL)
	{
		current_node = head;
		head = head->next;
		free(current_node->str);
		free(current_node);
	}
}
