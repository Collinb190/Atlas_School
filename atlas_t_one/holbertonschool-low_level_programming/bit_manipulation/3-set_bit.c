#include <stdio.h>
#include "main.h"

/**
 * set_bit - Sets the value of a bit to 1 at given index.
 * @n: A pointer to the number whose bit needs to be set.
 * @inddex: The index of the bit to set, starts at 0.
 * 
 * Return: 1 if it worked, or -1 if an error happened.
 */

int set_bit(unsigned long int *n, unsigned int index)
{
    if (index >= sizeof(unsigned long int) * 8)
    {
        return (-1);
    }
    *n |= (1 << index);
    return (1);
}