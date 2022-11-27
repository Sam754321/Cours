#include "libtam.h"

int ex_is_alpha(char c)
{
    if(!c)
        return -1;
    else if( (c <= 'z' && c >= 'a'))
        return 1;
    else if( (c <= 'Z' && c >= 'A'))
        return 2;
    else 
        return 0;
}