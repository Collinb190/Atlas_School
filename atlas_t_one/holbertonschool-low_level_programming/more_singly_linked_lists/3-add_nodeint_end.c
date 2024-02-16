#include <stdio.h>
#include "lists.h"

/**
 * add_nodeint - Adds a new node at the end of a list
 * @head: Pointer to a pointer to the head of the list.
 * @n: Value to be given to the new node
 * 
 * Return: The address of new element, or NULL if failed.
*/

listint_t *add_nodeint_end(listint_t **head, const int n)
{
    listint_t *newNode, *temp;
    newNode = malloc(sizeof(listint_t));
    if (newNode == NULL)
    {
        return (NULL);
    }
    newNode->n = n;
    newNode->next = NULL;
    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        temp = *head;
        while (temp->next != NULL)
        {
            temp = temp ->next;
        }
        temp->next = newNode;
    }
    return (newNode);
}