#include "libtam.h"

int ex_strcmp(const char *str1, const char *str2)
{
    if(str1 && str2)
    {
        while(str1 && str2)
        {
            if((*str1 - *str2 ) == 0 )
            {
                if((*str1 == '\0') && (*str2 =='\0'))
                    return 0;
                str1++;
                str2++;
            }
            else if((*str1 - *str2 ) > 0)
                return 1;
            else if((*str1 - *str2 ) < 0)
                return -1;    
        }
    }
    return 0;
}