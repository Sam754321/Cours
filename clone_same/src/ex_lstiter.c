#include "libtam.h"
#include<stdio.h>

void ex_lstiter(t_list *lst,void (*f)(void *elem))
{
    t_list *tmplst;
    t_list *nxlst;

    tmplst = NULL;
    nxlst = NULL;
    if(lst)
    {
        if(lst && f)
        {
            if(!lst->next)
            {
                f(lst->content);
                return;
            }
            nxlst = lst->next;
            tmplst = lst;
            while(tmplst)
            {
                nxlst = tmplst->next;
                f(tmplst->content);
                tmplst = nxlst;
            }
        }
    }
}