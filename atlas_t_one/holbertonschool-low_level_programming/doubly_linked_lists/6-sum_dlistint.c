#include <stdio.h>
#include "lists.h"
/**
 * sum_dlistint - Returns sum of all the data of a list.
 * @head: Pointer to the head of the linked list.
 * Return: The sum of all data in the list, or 0 if empty.
 */
int sum_dlistint(dlistint_t *head){
    int sum = 0;
    while(head != NULL){
        sum += head->n;
        head = head->next;
    }
    return(sum);
}