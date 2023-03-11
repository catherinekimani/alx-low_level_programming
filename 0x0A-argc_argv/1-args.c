#include <stdio.h>
/**
 * main - entry point
 * print number of args passed
 * @argc: ARGument Count
 * @argv: ARGument vector
 * Return: 0
 */
int main(int argc, char __attribute__((__unused__)) * argv[])
{
	printf("%d\n", argc - 1);

	return (0);
}
