#include "libtam.h"

unsigned long long ex_strlen(const char *str)
{
	unsigned long long ret;
	
	ret = 0;
	if(str)
	{	
		while(str[ret] != '\0')
		{
			ret++;
		}
		return ret;
	}
	return ret;
}