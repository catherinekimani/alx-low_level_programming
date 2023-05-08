#include "main.h"

void check_elf(unsigned char *e_ident);
void printf_magic(unsigned char *e_ident);
void print_class(unsigned char *e_ident);
void print_data(unsigned char *e_ident);
void print_version(unsigned char *e_ident);

/**
 * check_elf - checks whether the given file is an ELF file
 * @e_ident: pointer to the e_ident arr
 *
 * Return: void
 */
void check_elf(unsigned char *e_ident)
{
	int i;

	for (i = 0; i < 4; i++)
	{
		if (e_ident[i] != 127 &&
			e_ident[i] != 'E' &&
			e_ident[i] != 'L' &&
			e_ident[i] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}

/**
 * printf_magic - printts magic number of the ELF header
 * @e_ident: pointer to the e_ident arr
 *
 * Return: void
 */

void printf_magic(unsigned char *e_ident)
{
	int i;

	printf("  Magic:   ");

	for (i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x", e_ident[i]);

		if (i == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}

/**
 * print_class - prints class of an ELF header
 * @e_ident: pointer to the e_ident arr
 *
 * Return: void
 */
void print_class(unsigned char *e_ident)
{
	printf("  Class:                   ");

	switch (e_ident[EI_CLASS])
	{
	case ELFCLASSNONE:
		printf("none\n");
		break;
	case ELFCLASS32:
		printf("ELF32\n");
		break;
	case ELFCLASS64:
		printf("ELF64\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}

/**
 * print_data - print data of an ELF header
 * @e_ident: pointer to the e_ident arr
 *
 * Return: void
 */
void print_data(unsigned char *e_ident)
{
	printf("  Data:                ");

	switch (e_ident[EI_DATA])
	{
	case ELFDATANONE:
		printf("none\n");
		break;
	case ELFDATA2LSB:
		printf("2's complement, little endian\n");
		break;
	case ELFDATA2MSB:
		printf("2's complement, big endian\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}

/**
 * print_version - print version of an ELF header
 * @e_ident: pointer to the e_ident arr
 *
 * Return: void
 */
void print_version(unsigned char *e_ident)
{
	printf("  version                %d", e_ident[EI_VERSION]);

	switch (e_ident[EI_VERSION])
	{
	case EV_CURRENT:
		printf(" (currently)\n");
		break;
	default:
		printf("\n");
		break;
	}
}