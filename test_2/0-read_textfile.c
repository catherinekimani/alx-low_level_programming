#include "main.h"

/**
 * read_textfile - func that reads a text file and
 *                 prints it to the POSIX standard output.
 * @letters: the no. of letters it should read and print
 * @filename: file name to read
 *
 * Return: the actual no. of letters it could read and print
 *         if the file can not be opened or read, return 0
 *         if filename is NULL return 0
 *         if write fails or does not write the
 *         expected amount of bytes, return 0
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int file_descr;
	ssize_t read_len, write_len;
	char *buffer;

	if (filename == NULL)
		return (0);

	file_descr = open(filename, O_RDONLY);
	if (file_descr == -1)
		return (0);

	buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
	{
		close(file_descr);
		return (0);
	}

	read_len = read(file_descr, buffer, letters);
	close(file_descr);
	if (read_len == -1)
	{
		free(buffer);
		return (0);
	}

	write_len = write(STDOUT_FILENO, buffer, read_len);
	free(buffer);
	if (read_len != write_len)
		return (0);

	return (write_len);
}
