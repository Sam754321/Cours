#include "libtam.h"

int ex_strncmp(const char *str1, const char *str2, size_t n)
{
    size_t len;

    len = 0;
    if(str1 && str2 && n)
    {
        while(len < n)
        {
            if((*str1 - *str2 ) == 0 )
            {
                if((*str1 == '\0') && (*str2 =='\0'))
                    return 0;
                str1++;
                str2++;
                len++;
            }
            else if((*str1 - *str2 ) > 0)
                return 121;
            else if((*str1 - *str2 ) < 0)
                return -121;    
        }
    }
    return 0;
}