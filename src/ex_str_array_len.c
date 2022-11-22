#include "libtam.h"

size_t ex_str_array_len(const char **arr)
{
    size_t ret;

    ret = 0;
    if(arr)
    {
        while(*arr)
        {
            ret++;
            arr++;
        }
    }
    return ret;
}