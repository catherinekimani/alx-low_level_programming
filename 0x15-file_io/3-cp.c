#include "main.h"
void check_args(int argc);
int open_file_read(char *filename);
int open_file_write(char *filename);
void read_and_write(int fileFrom, int fileTo);
void close_file(int file);

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
	int fileFrom;

	fileFrom = open(filename, O_RDONLY);

	if (fileFrom == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", filename);
		exit(98);
	}
	return (fileFrom);/*descriptor*/
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
	int fileTo;

	fileTo = open(filename, O_WRONLY | O_CREAT | O_TRUNC,
			S_IRUSR | S_IWUSR | S_IWGRP | S_IROTH);

	if (fileTo == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", filename);
		exit(99);
	}
	return (fileTo); /*descriptor*/
}

/**
 * read_and_write - func to copy contents of one file to another
 *
 * @fileFrom: file descriptor for the file to read from
 * @fileTo: File descriptor for the file to write to
*/

void read_and_write(int fileFrom, int fileTo)
{
	int bufferSize = 1024, numBytesRead = 0;
	char buffer[1024];

	while (bufferSize == 1024)
	{
		bufferSize = read(fileFrom, buffer, 1024);

		if (bufferSize == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't read from file descriptor %d\n",
				fileFrom);

			exit(98);
		}
		numBytesRead = write(fileTo, buffer, bufferSize);

		if (numBytesRead < bufferSize)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to file descriptor %d\n",
				fileTo);
			exit(99);
		}
	}
}

/**
 * close_file - func to close file descriptor
 *
 * @file: file descriptor to close
*/

void close_file(int file)
{
	if (close(file) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close file descriptor %d\n", file);
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
	int fileFrom, fileTo;

	check_args(argc);

	fileFrom = open_file_read(argv[1]);
	fileTo = open_file_write(argv[2]);

	read_and_write(fileFrom, fileTo);

	close_file(fileFrom);

	close_file(fileTo);

	return (0);
}
