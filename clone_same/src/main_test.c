#include "./libtam.h"
#include "./colors.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <pwd.h>

int main(int ac, char **av) 
{
    if (ac > 1)
    {
        ex_print_dir_rec(av[1]);
    }
    return 0;
}