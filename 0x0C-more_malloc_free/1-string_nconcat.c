#include <stdlib.h>
#include "main.h"

/**
 * string_nconcat - Concatenates two strings, take n bytes from s2
 * @s1: The first string
 * @s2: The second string
 * @n: The number of bytes of s2 to concatenate
 *
 * Return: If memory allocation fails or s1 or s2 are NULL, returns NULL.
 *         Otherwise, returns a pointer to the concatenated string.
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	unsigned int s1_len = 0, s2_len = 0, i;
	char *result = NULL;

	/*NULL strings*/
	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	/*get string lengths */
	while (s1[s1_len])
		s1_len++;
	while (s2[s2_len])
		s2_len++;

	if (n >= s2_len)
		n = s2_len;

	/*Allocate memory*/
	result = (char *)malloc(sizeof(char) * (s1_len + n + 1));
	if (result == NULL)
		return (NULL);

	/*Copy s1 and the first n bytes of s2 to the result string*/
	for (i = 0; i < s1_len; i++)
		result[i] = s1[i];
	for (i = 0; i < n; i++)
		result[s1_len + i] = s2[i];

	/*Null-terminate the result string*/
	result[s1_len + n] = '\0';

	return (result);
}
