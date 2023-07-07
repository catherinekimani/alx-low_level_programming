#include "hash_tables.h"

/**
 * hash_table_create - function to create a hash table
 * @size: Array size
 *
 * Return: A ptr to the newly created hash table,
 *         else NULL
 */

hash_table_t *hash_table_create(unsigned long int size)
{
	unsigned long int idx;
	hash_table_t *table;

	/*allocate memory*/
	table = malloc(sizeof(hash_table_t));
	if (table == NULL)
		return (NULL);
	/*set size*/
	table->size = size;

	table->array = malloc(sizeof(hash_node_t *) * size);
	if (table->array == NULL)
	{
		free(table);
		return (NULL);
	}
	for (idx = 0; idx < size; idx++)
		table->array[idx] = NULL;
	return (table);
}
