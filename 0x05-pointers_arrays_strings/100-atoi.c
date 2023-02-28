#include "main.h"
/**
 * _atoi - convert string to interger
 * @s: pointer to convert
 * Return: an integer
 */
int _atoi(char *s)
{
	unsigned int i = 0;
	int sign = 1, result = 0;

	if (s[0] == '\0')
	{
		return (0);
	}

	if (s[0] == '-')
	{
		sign = -1;
		i++;
	}
	else if (s[0] == '+')
	{
		i++;
	}

	for (; s[i] != '\0'; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			result = result * 10 + (s[i] - '0');
		}
		else
		{
			break;
		}
	}

	return (sign * result);
}
