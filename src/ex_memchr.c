#include "libtam.h"

void *ex_memchr(const void *s, int c, size_t n)
{
    size_t len;
    void *ret;
    char *tmpstr;

    tmpstr = (char*)s;
    ret = NULL;
    len = 0;
    if(s && c && n)
    {
        while(len < n)
        {
            if((unsigned char)*tmpstr == (unsigned char)c)
            {
                ret = (void*)tmpstr;
                return ret;
            }
            tmpstr++;
            len++;
        }
    }
    return ret;
}