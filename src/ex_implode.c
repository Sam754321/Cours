#include "libtam.h"
#include <stdio.h>

static int count_arr(char **arr, int *len)
{
    int retnb;
    
    retnb = 0;
    while(arr && *arr)
    {
        *len += ex_strlen(*arr);
        retnb++;
        arr++;
    }
    return retnb;
}

static char *joinarr(char **arr, char c, int len)
{
    char *retstr;
    int i;
    int j;
    int k;
   
    i = 0;
    k = 0;
    retstr = NULL;
     if(arr && !c)
     {
        if(!(retstr = (char*)malloc(sizeof(char) * len + 1)))
            return NULL;
        while(arr[i])
        {
                j = 0;
                while(arr[i][j])
                {
                    retstr[k] = arr[i][j];
                    j++;
                    k++;
                }
                i++;
        }
        retstr[k] = 0;
     }
    return retstr;
}

static char *joinarr_char(char **arr, char c, int len, int count)
{
    char *retstr;
    int i;
    int j;
    int k;
   
    i = 0;
    k = 0;
    retstr = NULL;  
     if(arr && c)
     {
        if(!(retstr = (char*)malloc(sizeof(char) * len + count)))
            return NULL;
        while(arr[i])
        {
                j = 0;
                while(arr[i][j])
                {
                    retstr[k] = arr[i][j];
                    j++;
                    k++;
                }
                if(i < (count - 1))
                {
                    retstr[k] = c;
                    k++;
                }
                i++;
        }
        retstr[k] = 0;
     }
    return retstr;
}

char *ex_implode(char **arr, char c)
{
    char *retstr;
    int len;
    int count;

    count = 0;
    len = 0;
    retstr = NULL;
    if(arr)
    {
        count = count_arr(arr, &len);
        if(arr && !c)
        {
            retstr = joinarr(arr, c, len);
        }
        else if(arr && c)
        {
            retstr = joinarr_char(arr, c, len, count);
        }
    }
    return retstr;
}