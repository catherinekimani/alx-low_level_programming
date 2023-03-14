#include "main.h"
#include <stdlib.h>

/**
 * argstostr - function that Concatenates all the args of a program
 *
 * @ac: number of args
 * @av: array of pointers to the args
 *
 * Return: A pointer to a new string containing the concatenated args,
 *         or NULL if ac == 0 or av == NULL
 */
char *argstostr(int ac, char **av)
{
	char *result, *p;
	int i, j, total_len;

	if (ac == 0 || av == NULL)
		return (NULL);

	total_len = 0;
	for (i = 0; i < ac; i++)
	{
		char *arg = av[i];

		while (*arg != '\0')
		{
			total_len++;
			arg++;
		}
		total_len++;
	}
	result = malloc((total_len + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	p = result;
	for (i = 0; i < ac; i++)
	{
		char *arg = av[i];

		for (j = 0; arg[j] != '\0'; j++)
		{
			*p = arg[j];
			p++;
		}
		*p = '\n';
		p++;
	}
	*p = '\0';
	return (result);
}
