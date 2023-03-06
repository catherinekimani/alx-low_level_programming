#include "main.h"
#include<stddef.h>
/**
     * _strstr - function that locates a substring.
     * @haystack: string to be scanned
     * @needle:  small string to be searched with-in haystack string.
     * Return:  pointer to the beginning of the located substring
     */

char *_strstr(char *haystack, char *needle)
{
	char *ptr1;
	char *ptr2;
	char *ptr3;

	if (*needle == '\0')
	{
		return (haystack);
	}

	ptr1 = haystack;

	while (*ptr1 != '\0')
	{
		ptr2 = needle;
		ptr3 = ptr1;

		while (*ptr2 != '\0' && *ptr3 == *ptr2)
		{
			ptr3++;
			ptr2++;
		}
		if (*ptr2 == '\0')
		{
			return (ptr1);
		}
		ptr1++;
	}
	return (NULL);
}
