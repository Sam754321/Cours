#include "libtam.h"
#include<stdio.h>

char *ex_strchr(const char *str, int c)
{
	char *retstr;

	retstr = NULL;
	if(str)
	{
		retstr = (char*)str;
		while(*retstr)
		{
			if(*retstr == c)
				return retstr;
			retstr++;
		}
	}
	retstr = NULL;
	return retstr;
}