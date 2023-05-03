#include "lists.h"

/**
 * print_listint_safe - func that prints a listint_t list
 * @head: pointer to the head of the list
 *
 * Return: number of nodes in the list
 */

size_t print_listint_safe(const listint_t *head)
{
	size_t num_nodes;
	listint_t *current_node = (listint_t *)head;

	num_nodes = 0;
	while (current_node && current_node > current_node->next)
	{
		printf("[%p] %d\n", (void *)current_node, current_node->n);
		current_node = current_node->next;
		num_nodes++;
	}
	if (current_node)
	{
		printf("[%p] %d\n", (void *)current_node, current_node->n);
		printf("-> [%p] %d\n", (void *)current_node->next, current_node->next->n);
		num_nodes++;
	}
	
	if (!current_node)
		exit(98);

	return (num_nodes);
}
