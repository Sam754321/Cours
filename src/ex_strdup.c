#include "libtam.h"
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>



static size_t lenstr(const char *str)
{
	
	size_t ret;

	ret = 0;
	if(str)
	{	
		while(str[ret] != '\0')
		{
			ret++;
		}
		return ret;
	}
	return 0;
}

char *ex_strdup(const char *str)
{
	char *retstr;
	size_t size;
	size_t i;

	if(!str)
		return NULL;
	size = lenstr(str);
	if(!(retstr = (char*)malloc(size +1)))
		return NULL;
	i = 0;
	while(i < size)
	{
		retstr[i] = str[i];
		i++;
	}
	retstr[size] = 0;
	return retstr;
}