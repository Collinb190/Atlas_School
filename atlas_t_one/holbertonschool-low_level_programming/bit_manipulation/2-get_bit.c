#include <stdio.h>
#include "main.h"

/**
 * get_bit - Returns the value of a bit at a given index.
 * @n: The number to extract the bit from.
 * @index: The index of the bit to retrieve
 * 
 * Return: Value of the bit at given idex, or -1 for error
 */

int get_bit(unsigned long int n, unsigned int index)
{
    if (index >= (sizeof(unsigned long int) * 8))
    {
        return (-1);
    }
    return (n >> index) & 1;
}