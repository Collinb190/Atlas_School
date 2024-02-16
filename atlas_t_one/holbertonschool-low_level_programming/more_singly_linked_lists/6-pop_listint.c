#include <stdio.h>
#include "lists.h"

/**
 * pop_listint - Delets the head node of a linked list
 * @head: Pointer to a pointer to the head of the list
 * 
 * Return: the head nodes data (n), or 0 if empty
*/

int pop_listint(listint_t **head)
{
    int data = 0;
    listint_t *temp;
    if (head == NULL || *head == NULL)
    {
        return (0);
    }
    temp = *head;
    *head = (*head)->next;
    data = temp->n;
    free(temp);
    return (data);
}