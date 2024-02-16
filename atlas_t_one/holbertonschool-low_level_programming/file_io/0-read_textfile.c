#include <stdio.h>
#include "main.h"

/**
 * read_textfile - Reads a text file and prints it to the POSIX standard output.
 * @filename: Name of the file to be read.
 * @letters: Number of letters to read and print.
 *
 * Return: The actual number of letters it could read and print.
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
    int fd;
    ssize_t n_read;
    char buffer[1024];
    ssize_t n_printed = 0;
    if (filename == NULL)
    {
        return (0);
    }
    fd = open(filename, O_RDONLY);
    if (fd == -1)
    {
        return (0);
    }
    while ((n_read = read(fd, buffer, sizeof(buffer))) > 0 && n_printed < (ssize_t)letters)
    {
        ssize_t to_print = (n_printed + n_read > (ssize_t)letters) ? (ssize_t)letters - n_printed : n_read;
         if (write(STDOUT_FILENO, buffer, to_print) != to_print)
        {
            close(fd);
            return (0);
        }
        n_printed += to_print;
    }
     if (close(fd) == -1)
    {
        return (0);
    }
    return n_printed;
}