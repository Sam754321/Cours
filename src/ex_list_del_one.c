#include "libtam.h"

void ex_list_del_one(t_list *element, void (*del)(void *))
{
    void *content;
    
    if(element)
    {
        content = (void*)element->content;
        if(content && del)
            del(content);
        free(element);
        element = NULL;
    }
}