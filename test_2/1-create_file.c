#include "main.h"

/**
 * create_file -func that creates a file.
 * @filename: name of the file to create
 * @text_content:  is a NULL terminated string to write to the file
 *
 * Return: 1 on success
 *         -1 on failure (file can not be created
 *         file can not be written, write “fails”, etc…)
 */

int create_file(const char *filename, char *text_content)
{
	int file_decsr, wr, length = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (length = 0; text_content[length];)
			length++;
	}
	file_decsr = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
	wr = write(file_decsr, text_content, length);

	if (file_decsr == -1 || wr == -1)
		return (-1);

	close(file_decsr);
	return (1);
}
