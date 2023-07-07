#include "hash_tables.h"

/**
 * hash_table_delete - delets a hash table
 * @ht: Hash table
 */
void hash_table_delete(hash_table_t *ht)
{
	unsigned long int idx;
	hash_node_t *current_node, *next_node;

	for (idx = 0; idx < ht->size; idx++)
	{
		current_node = ht->array[idx];
		while (current_node != NULL)
		{
			next_node = current_node->next;
			free(current_node->key);
			free(current_node->value);
			free(current_node);
			current_node = next_node;
		}
	}
	free(ht->array);
	free(ht);
}
