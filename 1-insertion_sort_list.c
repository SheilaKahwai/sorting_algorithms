#include "sort.h"

/**
 * insertion_sort_list - algorithm to sort an unordered list
 * by inserting a node at the appropriate index
 * @list: double pointer to head of unordered list to sort
 */

void insertion_sort_list(listint_t **list)
{
    listint_t *temp, *curr;
    int flag;

    temp = (*list)->next;
    while (temp)
    {
	flag = 0;
        if (temp->n < temp->prev->n)
        {
            curr = temp->prev;
            while (curr)
            {
                if (curr > temp && curr != *list)
                {
                    curr->next = temp->next;
                    if (temp->next->prev)
                        temp->next->prev = curr;
                    temp->next = curr;
		    temp->prev = curr->prev;
		    curr->prev->next = temp;
		    curr->prev = temp;
                    curr = temp->prev;
		    flag = 1;
                }
                else if (curr > temp && curr == *list)
                {
                    temp->next = curr;
                    curr->prev = temp;
                    temp->prev = NULL;
		    flag = 1;
                }
                else
                {
                    temp->next = curr->next;
                    curr->next->prev = temp;
                    curr->next = temp;
                    temp->prev = curr;
		    flag = 1;
                }
		if (flag == 1)
			print_list(list);
            }
        }
        temp = temp->next;
    }
}
