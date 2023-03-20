#include <stdio.h>
#include <stdlib.h>
#include "dog.h"

/**
 * print_dog - Prints the attributes of a dog structure
 *
 * @d: A pointer to the dog structure to print
 *
 * This function prints the attributes of the
 * dog structure pointed to by @d. If any
 * attribute is NULL, it will be printed as "(nil)".
 */
void print_dog(struct dog *d)
{
	if (d == NULL)
	{
		return;
	}

	if (d->name == NULL)
	{
		d->name = "(nil)";
	}

	printf("Name: %s\n", d->name);
	printf("Age: %f\n", d->age);
	printf("Owner: %s\n", d->owner);
}
