#include "libtam.h"
#include <errno.h>

void ex_print_error_exit(char *str)
{
    char *ret;

    ret = "Error";
    if(str)
        ret = str;
    perror("");
    ex_putstr(ret);
    ex_putchar('\n');
    exit(1);
}