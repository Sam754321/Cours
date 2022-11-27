#include "libtam.h"

void *ex_memcpy(const void *dest, const void *src, size_t n)
{
    size_t len;
    char *ret;
    char *str;

    ret = (char*)dest;
    str = (char*)src;
    len = 0;
    if(dest && src && n)
    {
        while(len < n)
        {
           *ret = *str;
            ret++;
            str++;
            len++;
        }
    }
    return (void*)dest;
}