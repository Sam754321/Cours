#include "libtam.h"
#include <stdio.h>

static int checkset(char c, char *set)
{
    int i;

    i = 0;
    while(set[i])
    {
        if(c == set[i])
            return 1;
        i++;
    }
    return 0;
}

// retourne une string malloc jusqu'au char demander;
char *ex_strtrim(const char * str, char *set)
{
    char *retstr;
    int start;
    int end;

    start = 0;
    end = ex_strlen((char*)str);
    retstr = NULL;
    if(str && set)
    {
        while(checkset(str[start], set))
            start++;
        if(start < (end - 1))
        {
            while(checkset(str[end-1], set))
                end--;
        }
        retstr = ex_strsub(str, start, ( end - start )); 
    }
    return retstr;
} 