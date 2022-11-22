#include "libtam.h"
#include <stdio.h>

char *ex_strsub(const char *str, unsigned int start, size_t len)
{
    char *retstr;
    unsigned int i;

    i=0;
    retstr = NULL;
    if(str)
    {
        if(!(retstr = (char*)malloc(sizeof(char) * len + 1)))
        	return NULL;
        ex_memset(retstr,len + 1, 0);
        while(i < len)
        {
            retstr[i] = str[start + i];
            i++;
        }
    }
    return retstr;
}