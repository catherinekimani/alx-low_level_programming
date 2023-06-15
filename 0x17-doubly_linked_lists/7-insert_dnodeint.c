#include "lists.h"

/**
 * insert_dnodeint_at_index - func to insert new node
 * @h: pointer
 * @idx: index of the list
 * @n: value of the node
 *
 * Return: address of new, NULL if it fails
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new_node;
	dlistint_t *current;
	unsigned int indx;

	new_node = NULL;
	if (idx == 0)
		new_node = add_dnodeint(h, n);
	else
	{
		current = *h;
		indx = 1;
		if (current != NULL)
			while (current->prev != NULL)
				current = current->prev;
		while (current != NULL)
		{
			if (indx == idx)
			{
				if (current->next == NULL)
					new_node = add_dnodeint_end(h, n);
				else
				{
					new_node = malloc(sizeof(dlistint_t));
					if (new_node != NULL)
					{
						new_node->n = n;
						new_node->next = current->next;
						new_node->prev = current;
						current->next->prev = new_node;
						current->next = new_node;
					}
				}
				break;
			}
			current = current->next;
			indx++;
		}
	}

	return (new_node);
}
