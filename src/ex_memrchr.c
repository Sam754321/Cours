#include "libtam.h"

void *ex_memrchr(const void *s, int c, size_t n)
{
    size_t len;
    void *ret;
    char *tmpstr;

    tmpstr = (char*)s;
    tmpstr = &tmpstr[n];
    ret = NULL;
    len = n + 1;
    if(s && c && n)
    {
        while(len)
        {
            if((unsigned char)*tmpstr == (unsigned char)c)
            {
                ret = (void*)tmpstr;
                return ret;
            }
            tmpstr--;
            len--;
        }
    }
    return ret;
}