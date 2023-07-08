#include "hash_tables.h"

/**
 * shash_table_create - function to create a hash table
 * @size: Array size
 *
 * Return: Ptr to the newly created hash table,
 *         else NULL
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	unsigned long int idx;
	shash_table_t *table;

	table = malloc(sizeof(shash_table_t));
	if (table == NULL)
		return (NULL);
	table->size = size;
	table->array = malloc(sizeof(shash_node_t *) * size);
	if (table->array == NULL)
	{
		free(table);
		return (NULL);
	}
	for (idx = 0; idx < size; idx++)
		table->array[idx] = NULL;
	table->shead = NULL;
	table->stail = NULL;
	return (table);
}

/**
 * shash_table_set - Adds an element to the hash table
 * @ht: The hash table
 * @key: The key
 * @value: Value associated with the key
 *
 * Return: 1 SUCCESS, else 0
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	shash_node_t *new_node, *current;
	unsigned long int index;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	current = ht->shead;
	while (current)
	{
		if (strcmp(current->key, key) == 0)
		{
			free(current->value);
			current->value = strdup(value);
			return (1);
		}
		current = current->snext;
	}

	new_node = malloc(sizeof(shash_node_t));
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
	new_node->next = ht->array[index];
	ht->array[index] = new_node;

	if (ht->shead == NULL)
	{
		new_node->sprev = NULL;
		new_node->snext = NULL;
		ht->shead = new_node;
		ht->stail = new_node;
	}
	else if (strcmp(ht->shead->key, key) > 0)
	{
		new_node->sprev = NULL;
		new_node->snext = ht->shead;
		ht->shead->sprev = new_node;
		ht->shead = new_node;
	}
	else
	{
		current = ht->shead;
		while (current->snext != NULL && strcmp(current->snext->key, key) < 0)
			current = current->snext;
		new_node->sprev = current;
		new_node->snext = current->snext;
		if (current->snext == NULL)
			ht->stail = new_node;
		else
			current->snext->sprev = new_node;
		current->snext = new_node;
	}

	return (1);
}

/**
 * shash_table_get - retrieves a value associated with a key
 * @ht: The hash table
 * @key: The key
 *
 * Return: Value associated wuth the elem
 *         or NULL if key is not found
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	shash_node_t *temp;
	unsigned long int idx;

	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);
	idx = key_index((const unsigned char *)key, ht->size);

	if (idx >= ht->size)
		return (NULL);
	temp = ht->shead;

	while (temp != NULL)
	{
		if (strcmp(temp->key, key) == 0)
			return (temp->value);
		temp = temp->next;
	}
	return (NULL);
}

/**
 * shash_table_print - Prints a hash table in order
 * @ht: The hash table
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *sh_node;

	if (ht == NULL)
		return;
	sh_node = ht->shead;
	printf("{");
	while (sh_node != NULL)
	{
		printf("'%s': '%s'", sh_node->key, sh_node->value);
		sh_node = sh_node->snext;
		if (sh_node != NULL)
			printf(", ");
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - Prints a hash table in reverse order
 * @ht: The hash table
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *sh_node;

	if (ht == NULL)
		return;
	sh_node = ht->stail;
	printf("{");
	while (sh_node != NULL)
	{
		printf("'%s': '%s'", sh_node->key, sh_node->value);
		sh_node = sh_node->sprev;
		if (sh_node != NULL)
			printf(", ");
	}
	printf("}\n");
}

/**
 * shash_table_delete - deletes a hash table
 * @ht: The Hash table
 */
void shash_table_delete(shash_table_t *ht)
{
	shash_node_t *current_node, *next_node;
	shash_table_t *head = ht;

	if (ht == NULL)
		return;
	current_node = ht->shead;
	while (current_node)
	{
			next_node = current_node->snext;
			free(current_node->key);
			free(current_node->value);
			free(current_node);
			current_node = next_node;
	}
	free(ht->array);
	free(ht);
}
