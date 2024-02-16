#include <stdio.h>
#include "lists.h"

/**
 * lintint_len - Returns the number of elements in a list.
 * @h: Pointer to the head of the list.
 * 
 * Return: The number of elements(nodes) in the list.
*/

size_t listint_len(const listint_t *h)
{
    size_t nodeCount = 0;
    while (h != NULL)
    {
        h = h->next;
        nodeCount++;
    }
    return (nodeCount);
}