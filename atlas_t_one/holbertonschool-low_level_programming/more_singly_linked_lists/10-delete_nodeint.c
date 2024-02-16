#include <stdio.h>
#include "lists.h"

/**
 * delete_nodeint_at_index - delets the node at a given position
 * @head: Pointer to a pointer to the head of the list
 * @index: Index of the node to be deleted
 * 
 * Return: 1 if succeeded an -1 if failed.
*/

int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
    unsigned int i = 0;
    listint_t *current, *prev;
    if (*head == NULL)
    {
        return (-1);
    }
    current = *head;
    prev = NULL;
    while (current != NULL && i < index)
    {
        prev = current;
        current = current->next;
        i++;
    }
    if (current == NULL)
    {
        return (-1);
    }
    if (prev != NULL)
    {
        prev->next = current->next;
    }
    else
    {
        *head = current->next;
    }
    free (current);
    return (1);
}