#include <stdio.h>
/**
 * main - entry point
 * prints all args
 * @argc: ARGument Count
 * @argv: ARGument vector
 * Return: 0
 */
int main(int argc, char *argv[])
{
	int i;

	for (i = 0; i < argc; i++)
	{
		printf("%s\n", argv[i]);
	}
	return (0);
}

