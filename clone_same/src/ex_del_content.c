#include "libtam.h"

void ex_del_content(void *content)
{
    t_content *tmplst;

    tmplst = (t_content*)content;
    if(tmplst)
    {
        if(tmplst->path)
            free(tmplst->path);
        free(tmplst);
    }
}