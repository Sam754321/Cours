#include "libtam.h"
#include<stdio.h>

void ex_list_push_back(t_list **head, t_list *new)
{
    t_list *tmplist;

    if(head && new)
    {
        if(!(*head))
            (*head) = new;
        else if(*head && !((*head)->next) && (*head) != new )
            (*head)->next = new;
        else if((*head)->next)
        {
            tmplist = (*head);
            while(tmplist->next)
            {
                tmplist = tmplist->next;
            }
            tmplist->next = new;
        }
        
        
    }
}