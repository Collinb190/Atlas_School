#include <stdio.h>
#include "main.h"

/**
 * binary_to_unit - Converts a binary num to unsigned int.
 * @b: A pointer to a string of 0 and 1 chars.
 *
 * Return: The convert, or 0 if there is an invalid char 
 * or if the string is NULL.
 */

unsigned int binary_to_uint(const char *b)
{
    unsigned int result = 0;
    if (b == NULL)
    {
        return (0);
    }
    while (*b)
    {
        if (*b != '0' && *b != '1')
        {
            return (0);
        }
            result = (result << 1) + (*b - '0');
            b++;
    }
    return (result);
}