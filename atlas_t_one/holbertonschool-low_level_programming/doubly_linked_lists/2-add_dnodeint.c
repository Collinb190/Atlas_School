#include <stdio.h>
#include "lists.h"
/**
 * add_dnodeint - Adds a new node at the start of a list.
 * @head: Pointer to the head of the linked list.
 * @n: Value to be assigned to the new node.
 * Return: The address of the new element, or NULL if failed.
*/
dlistint_t *add_dnodeint(dlistint_t **head, const int n){
    dlistint_t *newNode;
    newNode = malloc(sizeof(dlistint_t));
    if(newNode == NULL)
        return(NULL);
    newNode->n = n;
    newNode->prev = NULL;
    newNode->next = *head;
    if(*head != NULL)
        (*head)->prev = newNode;
    *head = newNode;
    return(newNode);
}