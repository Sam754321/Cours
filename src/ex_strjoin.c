#include "libtam.h"
#include<stdio.h>

// 2eme occurence de cette fonction (ex_get_dir_list)
// peut etre la mettre en tant que fonction non static
// memset apres malloc toujours mieux
static char *malostr(const char *s1, const char *s2)
{
    char * retstr;
    size_t len;

    retstr = NULL;
    len = 0;
    if(s1 && s2)
    {
        len = ex_strlen((char*)s1) + ex_strlen((char*)s2) + 1;
        if(!(retstr = (char *)malloc(sizeof(char) * len)))
            return NULL;
    }
    else if(s1 && !s2)
    {
        len = ex_strlen((char*)s1) + 1;
        if(!(retstr = (char *)malloc(sizeof(char) * len)))
            return NULL;
    }
    else if(!s1 && s2)
    {
        len = ex_strlen((char*)s2) + 1;
        if(!(retstr = (char *)malloc(sizeof(char) * len)))
            return NULL;
    }
    ex_memset((void *)retstr, len, 0);
    return retstr;
}

char *ex_strjoin(const char *s1, const char *s2)
{
    char * retstr;
    int j;
    int i;

    retstr = NULL;
    i = 0;
    j = 0;
    if(s1 || s2)
    { 
        retstr = malostr(s1, s2);
        if(s1)
        {
            while(s1[i] != 0)
            {
                retstr[i] = s1[i];
                i++;
            }
        }
        if(s2)
        {
            while(s2[j] != 0)
            {
                retstr[i] = s2[j];
                i ++;
                j++;
            }
        }
        retstr[i] = 0;
    }
    return retstr;
}