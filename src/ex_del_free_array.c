#include "libtam.h"

void ex_del_free_array(char **arr)
{
    char **tmp_arr;

    tmp_arr = arr;
    if(arr && !(*arr))
    {
        free(arr);
        return;
    }
    while (tmp_arr && *tmp_arr)
    {
        free(*tmp_arr);
        *tmp_arr = NULL;
        tmp_arr++;
    }
    arr ? free(arr) : 0;
}