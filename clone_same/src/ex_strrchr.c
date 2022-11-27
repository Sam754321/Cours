#include "libtam.h"

char *ex_strrchr(const char *str, int c)
{
    int len;
	char *retstr;

	if(str)
	{
    		len = ex_strlen((char*)str);
		if(len > 0)
			retstr = (char*)&str[len-1];
		while(retstr || len > 1)
		{
			if(*retstr == c)
				return retstr;
			retstr--;
			len--;
		}
	}
	return NULL;
}