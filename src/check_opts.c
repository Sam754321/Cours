#include "libtam.h"

static int convert_alpha_num(int car)
{
    int ret;

    ret = -1;
    if(car >= 0 && car <= 26) // inutile ? le char est forcement alphanum donc a-z A-Z 0-9 
        ret = car + 97;
    else if(car >= 'a' && car <= 'z') // mettre la valeur en char (implique un cast implicite) est plus lisible
        ret = car - 'a';
    else if(car >= 'A' && car <= 'Z')
        ret = car - 'A';
    return ret;
}

static void push_bit_flag(int type,  long *option, int flag)
{
    
    if(type == SET_OPTS)
        *option |= 1 << convert_alpha_num(flag);
    else if(type == XOR_OPTS )
        *option ^= 1 << convert_alpha_num(flag);
    else if(type == SUPR_OPTS )
        *option -= 0 << convert_alpha_num(flag);
    else if(type == LAST_OPTS )
    {
        *option = 0;
        *option |= 1 << convert_alpha_num(flag);
    }
}

int check_opts(char *str, char *list_option,  long *options, int type)
{
    int i;
    int j;

    i = 1;
    if(!str || !list_option ||!(*str) || !(*list_option))
        return 0;
    else if(str[0] != '-' || (str[0] == '-' && str[1] == '-') )
        return 0;
    else if(str[0] == '-')
    {
        while(str[i])
        {
            j = ex_is_alpha(str[i]);
            if(ex_cmp_char_str(str[i], list_option) != 0 && j != 1 && j != 2)
                return -1;
            else if(j == 1 || j == 2)
                push_bit_flag(type, options, str[i]);
            i++;
        }
    }
    return (i -1); // indentation !
}