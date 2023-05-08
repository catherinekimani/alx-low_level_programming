#include "main.h"

#define BUF_SIZE 1024

/**
 * main - Program that copies content of one file to another
 * @argc: No. of args
 * @argv: Array of strings
 *
 * Return: 0 on success
 */
int main(int argc, char **argv)
{
	int src_fd, dest_fd, r_count, w_count;
	char *buffer;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buffer = malloc(sizeof(char) * BUF_SIZE);
	if (!buffer)
		return (0);

	dest_fd = open(argv[1], O_RDONLY);
	handle_error_98(dest_fd, buffer, argv[1]);
	src_fd = open(argv[2], O_WRONLY | O_TRUNC | O_CREAT, 0664);
	handle_error_99(src_fd, buffer, argv[2]);
	do {
		r_count = read(dest_fd, buffer, BUF_SIZE);
		if (r_count == 0)
			break;
		handle_error_98(r_count, buffer, argv[1]);
		w_count = write(src_fd, buffer, r_count);
		handle_error_99(w_count, buffer, argv[2]);
	} while (w_count >= BUF_SIZE);
	r_count = close(src_fd);
	handle_error_100(r_count, buffer);
	r_count = close(dest_fd);
	handle_error_100(r_count, buffer);
	free(buffer);
	return (0);
}

/**
 * handle_error_98 - check for error code 98 & handle it
 * @src_fd: file descriptor to check
 * @buffer: pointer to buffer
 * @argv: name of file passed as an arg
 */

void handle_error_98(int src_fd, char *buffer, char *argv)
{
	if (src_fd < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv);
		free(buffer);
		exit(98);
	}
}

/**
 * handle_error_99 - check for error code 99 & handle it
 * @src_fd: file descriptor to check
 * @buffer: pointer to buffer
 * @argv: name of file passed as an arg
 */

void handle_error_99(int src_fd, char *buffer, char *argv)
{
	if (src_fd < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv);
		free(buffer);
		exit(99);
	}
}

/**
 * handle_error_100 - check for error code 100 & handle it
 * @src_fd: file descriptor to check
 * @buffer: pointer to buffer
 */

void handle_error_100(int src_fd, char *buffer)
{
	if (src_fd < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %i\n", src_fd);
		free(buffer);
		exit(100);
	}
}
