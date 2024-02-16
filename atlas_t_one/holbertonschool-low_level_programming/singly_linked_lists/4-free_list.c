#include <stdio.h>
#include "lists.h"

/**
 * this will contain some notes
 * this will explain the code
*/

void free_list(list_t *head)
{
    list_t *temp;
    while (head != NULL)
    {
        temp = head->next;
        free (head->str);
        free (head);
        head = temp;
    }
}