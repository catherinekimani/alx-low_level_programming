#include "hash_tables.h"

/**
 * hash_table_set - adds an element to the hash table
 * @ht: Hash table
 * @key: The key
 * @value: The value associated with the key
 *
 * Return: 1 SUCCESS, else 0
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int idx;
	hash_node_t *new_node, *current;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);
	
	idx = key_index((const unsigned char *)key, ht->size);
	current = ht->array[idx];
	while (current != NULL)
	{
		if (strcmp(current->key, key) == 0)
		{
			free(current->value);
			current->value = strdup(value);
			if (current->value == NULL)
				return (0);
			return (1);
		}
		current = current->next;
	}
	new_node = malloc(sizeof(hash_node_t));
	if (new_node == NULL)
	{
		return (0);
	}
	new_node->key = strdup(key);
	if (new_node->key == NULL)
	{
		free(new_node);
		return (0);
	}
	new_node->value = strdup(value);
	if (new_node->value == NULL)
	{
		free(new_node->key);
		free(new_node);
		return (0);
	}
	new_node->next = ht->array[idx];
	ht->array[idx] = new_node;
	return (1);
}
