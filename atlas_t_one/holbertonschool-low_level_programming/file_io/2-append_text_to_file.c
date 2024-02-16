#include "main.h"
#include <stdio.h>

/**
 * append_text_to_file - Appends text at the end of a file.
 * @filename: Name of the file.
 * @text_content: NULL terminated string to add at the end of the file.
 *
 * Return: 1 on success, -1 on failure.
 */

int append_text_to_file(const char *filename, char *text_content)
{
    int fd;
    int write_status;

    if (filename == NULL || text_content == NULL)
        return -1;

    fd = open(filename, O_WRONLY | O_APPEND);

    if (fd == -1)
        return -1;

    write_status = write(fd, text_content, strlen(text_content));

    if (close(fd) == -1)
        return -1;

    return (write_status == -1) ? -1 : 1;
}