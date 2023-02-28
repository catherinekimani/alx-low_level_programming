#include "main.h"
/**
 * _atoi - convert string to interger
 * @s: pointer to convert
 * Return: an integer
 */
int _atoi(char *s)

{

	int i = 0;
	unsigned int result = 0;
	int sign = 1;
	int hasDigits = 0;

	while (s[i])
	{
		if (s[i] == '-')
		{
			sign *= -1;
		}
		while (s[i] >= '0' && s[i] <= '9')
		{
			hasDigits = 1;
			result = (result * 10) + (s[i] - '0');
			i++;
		}
		if (hasDigits == 1)
		{
			break;
		}
		i++;
	}
	result *= sign;
	return (result);
}
