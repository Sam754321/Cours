#include "libtam.h"

int ex_cmp_char_str(char c, char *str)
{
    int i;

    i = 0;
    if(!c || !str)
        return -1;
    while(str[i])
    {
        printf("char :%c c___str[i] == %c\n", c, str[i]);
        if(str[i] == c)
            return 0;
        i++;
    }
    return 1;
}