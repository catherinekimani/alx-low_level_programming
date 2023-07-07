#include "hash_tables.h"
/**
 * key_index - function to get the index of a key
 * @key: the key
 * @size: Array size of the hash table
 *
 * Return: Index
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	unsigned long int hash_value;
	unsigned long int idx;

	/*calculate hash value first*/
	hash_value = hash_djb2(key);
	/*get index*/
	idx = hash_value % size;
	return (idx);
}
