#include <stdio.h>
#include "lists.h"

/**
 * this will contain my notes
 * this will explain the code
*/

list_t *add_node_end(list_t **head, const char *str)
{
    list_t *newNode, *temp;
    if (str == NULL)
    {
        return (NULL);
    }
    newNode = malloc(sizeof(list_t));
    if (newNode == NULL)
    {
        return (NULL);
    }
    newNode->str = strdup(str);
    if (newNode->str == NULL)
    {
        free (newNode);
        return (NULL);
    }
    newNode->len = strlen(str);
    newNode->next = NULL;
    if (*head == NULL)
    {
        *head = newNode;
        return (newNode);
    }
    temp = *head;
    while (temp->next  != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    return (newNode);
}