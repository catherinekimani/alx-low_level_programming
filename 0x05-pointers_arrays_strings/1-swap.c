# include "main.h"
/**
 * swap_int - function that swaps the values of two integers
 * @a: first character to bbe checked
 * @b: second character to be checked
 * Return: 0
 */
void swap_int(int *a, int *b)
{
	int tempVar; /* create a temporary variable*/

	tempVar = *a;
	*a = *b;
	*b = tempVar;
}
