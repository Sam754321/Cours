#include "libtam.h"

t_list *ex_list_last(t_list *list)
{
    t_list *retlist;

    retlist = NULL;
    if(list)
    {
        retlist = list;
        while(retlist->next)
            retlist = retlist->next;
    }
    return retlist;
}