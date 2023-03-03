#include "main.h"
/**
 * reverse_array -  function that reverses the content
 * of an array of integers.
 * @n: number of elements in the array
 * @a: pointer to int
 * Return: 0;
 */
void reverse_array(int *a, int n)
{
	int i;
	int temp;

	for (i = 0; i < (n / 2); i++ :)
	{
		temp = a[i];
		a[i] = a[n - i - 1];
		a[n - i - 1] = temp;
	}
}
