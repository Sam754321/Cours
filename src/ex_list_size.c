#include "libtam.h"

size_t ex_list_size(t_list *list)
{
    size_t retlen;
    t_list *tmplist;

    retlen = 0;
    if(list)
    {
        if(!(list->next))
            return 1;
        tmplist = list;
        while(tmplist)
        {
            tmplist = tmplist->next;
            retlen++;
        }
    }
    return retlen;
}