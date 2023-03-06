#include "main.h"
#include <stdio.h>
/**
 * print_diagsums - Print the sum of the 2 diagonals of a square matrix of ints
 * @a: 2d array of int types
 * @size: size of array (square)
 */

void print_diagsums(int *a, int size)
{
	int sum1 = 0, sum2 = 0;
	int i, j;

	for (i = 0; i < size; i++)
	{
		sum1 += *(a + i * size + i);
	}

	for (i = 0, j = size - 1; i < size; i++, j--)
	{
		sum2 += *(a + i * size + j);
	}

	printf("Sum of first diagonal: %d\n", sum1);
	printf("Sum of second diagonal: %d\n", sum2);
}
