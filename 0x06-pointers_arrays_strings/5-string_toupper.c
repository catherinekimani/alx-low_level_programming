# include "main.h"
/**
 * string_toupper - function that changes all lowercase
 * letters of a string to uppercase
 * @str:a string
 * Return:str
 */
char *string_toupper(char *str)
{
	int i = 0;

	while (str[i])
	{
		str[i] = toupper(str[i]);
		i++;
	}
	return (str);
}
