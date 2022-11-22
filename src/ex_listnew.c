#include "libtam.h"

t_list *ex_listnew(void *content)
{
    t_list *retlist;

    if(!(retlist = (t_list*)malloc(sizeof(t_list))))
            return NULL;
    retlist->content = content;
    retlist->next = NULL;

    return retlist;

}