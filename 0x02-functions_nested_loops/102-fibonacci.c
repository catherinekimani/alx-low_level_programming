#include <stdio.h>

/**
  * main - Prints the first 52 fibonacci numbers
  *
  * Return: Nothing!
  */
int main(void)
{
	int num1 = 0;
	long num2 = 1, num3 = 2;

	while (num1 < 50)
	{
		if (num1 == 0)
			printf("%ld", num2);
		else if (num1 == 1)
			printf(", %ld", num3);
		else
		{
			num3 += num2;
			num2 = num3 - num2;
			printf(", %ld", num3);
		}

		++num1;
	}

	printf("\n");
	return (0);
}
