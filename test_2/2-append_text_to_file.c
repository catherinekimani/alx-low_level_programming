#include "main.h"

/**
 * append_text_to_file - func that appends text at the end of a file.
 * @filename: the name of the file
 * @text_content: the NULL terminated str to add at the end of the file
 *
 * Return: 1 on success
 *        -1 on failure
 */

int append_text_to_file(const char *filename, char *text_content)
{
	int file_descr, wr, length = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (length = 0; text_content[length];)
			length++;
	}

	file_descr = open(filename, O_WRONLY | O_APPEND);
	wr = write(file_descr, text_content, length);

	if (file_descr == -1 || wr == -1)
		return (-1);

	close(file_descr);

	return (1);
}
