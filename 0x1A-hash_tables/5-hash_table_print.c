#include "hash_tables.h"

/**
 * hash_table_print - Prints a hash table
 * @ht: The Hash table
 */
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int idx;
	unsigned char flag = 0;
	hash_node_t *current_node;

	if (ht == NULL)
		return;

	printf("{");

	for (idx = 0; idx < ht->size; idx++)
	{
		if (ht->array[idx] != NULL)
		{
			if (flag == 1)
				printf(", ");
			current_node = ht->array[idx];
			while (current_node != NULL)
			{
				printf("'%s': '%s'", current_node->key, current_node->value);
				current_node = current_node->next;
				if (current_node != NULL)
					printf(", ");
			}
			flag = 1;
		}
	}
	printf("}\n");
}
