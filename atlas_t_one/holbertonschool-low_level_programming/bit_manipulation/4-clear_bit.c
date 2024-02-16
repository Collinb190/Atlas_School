#include <stdio.h>
#include "main.h"

/**
 * clear_bit - Sets the value of a bit to 0 at given index.
 * @n: A pointer to the number whose bit needs to be cleared.
 * @inddex: The index of the bit to clear, starts at 0.
 * 
 * Return: 1 if it worked, or -1 if an error happened.
 */


int clear_bit(unsigned long int *n, unsigned int index)
{
    if (index >= sizeof(unsigned long int) * 8)
    {
        return (-1);
    }
    *n &= ~(1 << index);
    return (1);
}