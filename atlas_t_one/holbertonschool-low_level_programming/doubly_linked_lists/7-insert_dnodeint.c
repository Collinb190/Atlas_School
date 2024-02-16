#include <stdio.h>
#include "lists.h"
/**
 * insert_dnodeint_at_index - Adds a new node at given position.
 * @h: Pointer to the head of the linked list.
 * @idx: Index where the new node should be added.
 * @n: Value of the new node.
 * Return: The address of the new node, or NULL if failed.
 */

dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n){
    dlistint_t * newNode, *temp;
    unsigned int i;
    if(h == NULL) return(NULL);
    newNode = malloc(sizeof(dlistint_t));
    if(newNode == NULL) return(NULL);
    newNode->n = n;
    newNode->prev = NULL;
    newNode->next = NULL;
    if(idx == 0){
        newNode->next = *h;
        if(*h != NULL) (*h)->prev = newNode;
        *h = newNode;
        return(newNode);
    }
    temp = *h;
    for (i = 0; i < idx -1 && temp != NULL; i++) temp = temp->next;
    if(temp == NULL && i < idx - 1){
        free(newNode);
        return(NULL);
    }
    newNode->next = temp->next;
    newNode-> prev = temp;
    if(temp->next != NULL) temp->next->prev = newNode;
    temp->next = newNode;
    return(newNode);
}