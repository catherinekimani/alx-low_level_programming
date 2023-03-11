#include <stdio.h>
#include <stdlib.h>
/**
 * main - entry point
 * multiply two numbers
 * @argc: ARGument Count
 * @argv: ARGument vector
 * Return: 1 if program doesn't get 2 args
 */
int main(int argc, char *argv[])
{
	int x, y, result;

	if (argc != 3)
	{
		printf("Error\n");
		return (1);
	}

	x = atoi(argv[1]);
	y = atoi(argv[2]);
	result = x * y;

	printf("%d\n", result);
	return (0);
}
