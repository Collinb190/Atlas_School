#include <stdio.h>
#include "lists.h"
/**
 * delete_dnodeint_at_index - Deletes a node at given position.
 * @head: Pointer to the head of the linked list.
 * @index: Index where the new node should be deleted.
 * Return: 1 if it went good, -1 if it went bad.
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index){
    dlistint_t *temp, *prev;
    unsigned int i;
    if(!head || !*head) return(-1);
    temp = *head;
    if(index == 0){
        *head = temp->next;
        if(*head != NULL) (*head)->prev = NULL;
        free(temp);
        return(1);
    }
    for(i = 0; i < index && temp != NULL; i++){
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL && i < index) return(-1);
    prev->next = temp->next;
    if(temp->next != NULL) temp->next->prev = prev;
    free(temp);
    return(1);
}