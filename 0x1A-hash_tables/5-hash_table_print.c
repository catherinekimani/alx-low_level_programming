#include "hash_tables.h"

/**
 * hash_table_print - Prints a hash table
 * @ht: The Hash table
 */
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int idx = 0;
	int flag = 0;
	hash_node_t *current_node;

	if (ht == NULL)
		return;

	printf("{");

	for (idx = 0; idx < ht->size; idx++)
	{
		current_node = ht->array[idx];
		while (current_node != NULL)
		{
			if (flag == 1)
			printf(", ");
		printf("'%s' : '%s'", current_node->key, current_node->value);
		flag = 1;
		current_node = current_node->next;
		}
	}
	printf("}\n");
}
