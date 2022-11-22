#include "libtam.h"

void ex_list_push_front(t_list **head, t_list *new)
{
    if(head && new)
    {
        if((*head) && (*head) != new)
        {
            new->next = (*head);
            (*head) = new;
        }
        else if(!(*head))
        {
            (*head) = new;
        }
    }
}