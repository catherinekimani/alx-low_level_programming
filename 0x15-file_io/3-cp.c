#include "main.h"
void check_args(int argc);
int open_file_read(char *filename);
int open_file_write(char *filename);
void read_and_write(int file_from, int file_to);
void close_file(int FD_VALUE);

/**
 * check_args - check that there are 3-command-line args
 *
 * @argc: No. of command-line args
 */

void check_args(int argc)
{
	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
}

/**
 * open_file_read - func to open file for reading
 *
 * @filename: Name of file to open
 *
 * Return: file descriptor for te opened file
*/

int open_file_read(char *filename)
{
	int file_from;

	file_from = open(filename, O_RDONLY);

	if (file_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", filename);
		exit(98);
	}
	return (file_from);/*descriptor*/
}

/**
 * open_file_write - func to open file for writing
 *
 * @filename: Name of file to open
 *
 * Return: file descriptor for the opened file
*/

int open_file_write(char *filename)
{
	int file_to;

	file_to = open(filename, O_WRONLY | O_CREAT | O_TRUNC,
			S_IRUSR | S_IWUSR | S_IWGRP | S_IROTH);

	if (file_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to file %s\n", filename);
		exit(99);
	}
	return (file_to); /*descriptor*/
}

/**
 * read_and_write - func to copy contents of one file to another
 *
 * @file_from: file descriptor for the file to read from
 * @file_to: File descriptor for the file to write to
*/

void read_and_write(int file_from, int file_to)
{
	int bufferSize = 1024, numBytesRead = 0;
	char buffer[1024];

	while (bufferSize == 1024)
	{
		bufferSize = read(file_from, buffer, 1024);

		if (bufferSize == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't read from file %d\n",
				file_from);

			exit(98);
		}
		numBytesRead = write(file_to, buffer, bufferSize);

		if (numBytesRead < bufferSize)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to file %d\n",
				file_to);
			exit(99);
		}
	}
}

/**
 * close_file - func to close file descriptor
 *
 * @FD_VALUE: file descriptor to close
 */

void close_file(int FD_VALUE)
{
	if (close(FD_VALUE) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", FD_VALUE);
		exit(100);
	}
}

/**
 * main - Program that copies content of one file to another
 * @argc: No. of args
 * @argv: Array of strings
 *
 * Return: 0 on success
*/

int main(int argc, char *argv[])
{
	int file_from, file_to;

	check_args(argc);

	file_from = open_file_read(argv[1]);
	file_to = open_file_write(argv[2]);

	read_and_write(file_from, file_to);

	close_file(file_from);

	close_file(file_to);

	return (0);
}
