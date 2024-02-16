#include <stdio.h>
#include "lists.h"
/**
 * Write a function that returns the number of elements in a linked list_t list.
 * Prototype: size_t list_len(const list_t *h);
 */

size_t list_len(const list_t *h)
{
    size_t elementCount = 0;
    while (h != NULL)
    {
        elementCount++;
        h = h->next;
    }
    return (elementCount);
}
