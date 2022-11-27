#include "libtam.h"

void ex_list_del_all(t_list **head, void (*del)(void *))
{
    t_list *tmplst;
    t_list *nxtmp;

    if(head && *head)
    {
        tmplst = *head;
        if(tmplst && del)
        {
            nxtmp = tmplst->next;
            if(!nxtmp)
            {
                if(tmplst->content)
                    del(tmplst->content);
                free(tmplst);
                tmplst = NULL;
                return;
            }
            while(tmplst)
            {
                if(tmplst->content)
                    del(tmplst->content);
                nxtmp = tmplst->next;
                free(tmplst);
                tmplst = NULL;
                tmplst = nxtmp;
            }   
        }      
    }
}