#include <stdio.h>
#include "lists.h"
/**
 * get_dnodeint_at_index - Returns the nTH node of a list.
 * @head: Pointer to the head of the linked list.
 * @index: Index of the node to get starting at 0.
 * Return: Nth node or NULL if the node does not exist.
*/
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index){
    unsigned int i;
    for(i = 0; i < index && head != NULL; i++)
        head = head->next;
    if(i < index || head == NULL)
        return(NULL);
    return(head);
}