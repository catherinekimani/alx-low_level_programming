# include <stdio.h>
/**
 * main -entry point
 * program that prints putchar followed by a new line
 * Return: Always 0 (Success)
 */
int main(void)
{
	char str[] = "_putchar";
	int i = 0;

	while (str[i] != '\0')
	{
		putchar(str[i]);
		i++;
	}
	putchar('\n');
	return (0);
}
