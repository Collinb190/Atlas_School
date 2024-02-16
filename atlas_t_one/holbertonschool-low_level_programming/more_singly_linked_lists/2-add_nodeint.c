#include <stdio.h>
#include "lists.h"

/**
 * add_nodeint - Adds a new node at the start of a list
 * @head: Pointer to a pointer to the head of the list.
 * @n: Value to be given to the new node
 * 
 * Return: The number of elements(nodes) in the list.
*/

listint_t *add_nodeint(listint_t **head, const int n)
{
    listint_t *newNode;
    newNode = malloc(sizeof(listint_t));
    if (newNode == NULL)
    {
        return(NULL);
    }
    newNode->n =n;
    newNode->next = *head;
    *head = newNode;
    return (newNode);
}