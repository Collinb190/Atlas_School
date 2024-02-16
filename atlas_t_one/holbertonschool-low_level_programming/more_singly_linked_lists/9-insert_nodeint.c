#include <stdio.h>
#include "lists.h"

/**
 * insert_nodeint_at_index - Inerts a node at given position
 * @head: Pointer to a pointer to the head of the list
 * @idx: Index where the new node should be added
 * @n: Value to be given by the new node
 * 
 * Return: Sum of all the data, or 0 if empty
*/

listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
    unsigned int i =0;
    listint_t *newNode, *current = *head, *prev = NULL;
    newNode = malloc(sizeof(listint_t));
    if (newNode == NULL)
    {
        return (NULL);
    }
    newNode->n = n;
    while (current != NULL && i < idx)
    {
        prev = current;
        current = current->next;
        i++;
    }
    if (i < idx)
    {
        free (newNode);
        return (NULL);
    }
    if (prev != NULL)
    {
        prev->next = newNode;
    }
    else
    {
        *head = newNode;
    }
    newNode->next = current;
    return (newNode);
}