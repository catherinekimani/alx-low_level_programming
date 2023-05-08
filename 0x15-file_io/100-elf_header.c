#include "main.h"

void check_elf(unsigned char *e_ident);
void print_magic(unsigned char *e_ident);
void print_class(unsigned char *e_ident);
void print_data(unsigned char *e_ident);
void print_version(unsigned char *e_ident);
void print_osabi(unsigned char *e_ident);
void print_abi(unsigned char *e_ident);
void close_elf(int elf);

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
 * print_magic - printts magic number of the ELF header
 * @e_ident: pointer to the e_ident arr
 *
 * Return: void
 */

void print_magic(unsigned char *e_ident)
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

/**
 * print_osabi - print OS/ABI of an ELF header
 * @e_ident: pointer to the e_ident arr
 *
 * Return: void
 */

void print_osabi(unsigned char *e_ident)
{
	printf("OS/ABI:                            ");

	switch (e_ident[EI_OSABI])
	{
	case ELFOSABI_NONE:
		printf("UNIX - System V\n");
		break;
	case ELFOSABI_HPUX:
		printf("UNIX - HP-UX\n");
		break;
	case ELFOSABI_NETBSD:
		printf("UNIX - NetBSD\n");
		break;
	case ELFOSABI_LINUX:
		printf("UNIX - Linux\n");
		break;
	case ELFOSABI_SOLARIS:
		printf("UNIX - Solaris\n");
		break;
	case ELFOSABI_IRIX:
		printf("UNIX - IRIX\n");
		break;
	case ELFOSABI_FREEBSD:
		printf("UNIX - FreeBSD\n");
		break;
	case ELFOSABI_TRU64:
		printf("UNIX - TRU64\n");
		break;
	case ELFOSABI_ARM:
		printf("ARM\n");
		break;
	case ELFOSABI_STANDALONE:
		printf("Standalone App\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_OSABI]);
	}
}

/**
 * print_abi - print ABI version on an ELF header
 * @e_ident: pointer to the e_ident arr
 *
 * Return: void
 */

void print_abi(unsigned char *e_ident)
{
	printf("  ABI Version             %d\n", e_ident[EI_ABIVERSION]);
}

/**
 * close_elf - close an ELF file
 * @elf: file descriptor
 */

void close_elf(int elf)
{
	if (close(elf) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", elf);
		exit(98);
	}
}

/**
 * main - entry point
 * @argc: number of args
 * @argv: pointer to array of args
 *
 * Return: 0  success, 98  failure
 */

int main(int __attribute__((__unused__)) argc, char *argv[])
{
	Elf64_Ehdr *header;
	int fd, bytes_read;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}

	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		close_elf(fd);
		dprintf(STDERR_FILENO, "Error can't read file %s\n", argv[1]);
		exit(98);
	}

	bytes_read = read(fd, header, sizeof(Elf64_Ehdr));
	if (bytes_read == -1)
	{
		free(header);
		close_elf(fd);
		dprintf(STDERR_FILENO, "Error:`%s`: No such file\n", argv[1]);
		exit(98);
	}

	check_elf(header->e_ident);
	printf("ELF Header: \n");
	print_magic(header->e_ident);
	print_class(header->e_ident);
	print_data(header->e_ident);
	print_version(header->e_ident);
	print_osabi(header->e_ident);
	print_abi(header->e_ident);

	free(header);
	close_elf(fd);
	return (0);
}
