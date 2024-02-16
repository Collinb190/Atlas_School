#include "main.h"
#include <stdio.h>

#define BUFFER_SIZE 1024

/**
 * main - Copies the content of a file to another file.
 * @argc: Number of arguments.
 * @argv: Array of arguments.
 *
 * Return: 0 on success, exit codes as specified in the requirements on failure.
 */
int main(int argc, char *argv[])
{
    int fd_from, fd_to;
    ssize_t n_read, n_write;
    char buffer[BUFFER_SIZE];

    /* Check the number of arguments */
    if (argc != 3)
    {
        dprintf(2, "Usage: %s file_from file_to\n", argv[0]);
        exit(97);
    }

    /* Open the source file for reading */
    fd_from = open(argv[1], O_RDONLY);
    if (fd_from == -1)
    {
        dprintf(2, "Error: Can't read from file %s\n", argv[1]);
        exit(98);
    }

    /* Open or create the destination file for writing */
    fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
    if (fd_to == -1)
    {
        dprintf(2, "Error: Can't write to file %s\n", argv[2]);
        close(fd_from);
        exit(99);
    }

    /* Copy content from source to destination */
    while ((n_read = read(fd_from, buffer, BUFFER_SIZE)) > 0)
    {
        n_write = write(fd_to, buffer, n_read);
        if (n_write == -1)
        {
            dprintf(2, "Error: Can't write to file %s\n", argv[2]);
            close(fd_from);
            close(fd_to);
            exit(99);
        }
    }

    /* Check for read error */
    if (n_read == -1)
    {
        dprintf(2, "Error: Can't read from file %s\n", argv[1]);
        close(fd_from);
        close(fd_to);
        exit(98);
    }

    /* Close file descriptors */
    if (close(fd_from) == -1 || close(fd_to) == -1)
    {
        dprintf(2, "Error: Can't close fd %d\n", (close(fd_from) == -1) ? fd_from : fd_to);
        exit(100);
    }

    return 0;
}