# include "main.h"
# include <stdio.h>
/**
* print_to_98 - prints numbers to 98
* @n: starting integer
*
* Description: prints all natural number from n - 98
*
* Return: 0
*/
void print_to_98(int n)
{
	while (n <= 98)
	{
		printf("%d", n);
		if (n  != 98)
		{
			printf(",");
			printf(" ");
		}
		n++;
	}
	printf("\n");
}

