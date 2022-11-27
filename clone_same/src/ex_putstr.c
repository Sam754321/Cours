#include "libtam.h"
#include <unistd.h>

void ex_putstr(char *str)
{
    if(!str)
        return;
    write(1,str,ex_strlen(str));
}