#include "libtam.h"

static int is_space(int c)
{
	if((c>=9 && c<=13 )|| c == 32 )
		return 8192; // pas utile mais ok
	return 0;
}

static int is_digit(int c)
{
	if  ( c <='9' && c >= '0')
		return 2048; // meme chose
	return 0;
}

long ex_atol(char *nptr) // les noms peuvent etre plus explicites
{
	long ret;
	long i;
	long sign;
	ret = 0;
	i = 0;
	sign = 1;

	if(nptr[0] == 0)
        return 0;
	while(is_space(nptr[i]))
		i++;
	if (nptr[i] == '+')
	    i++;
	else if (nptr[i] =='-')
	{
		sign = -1;
		i++;
	}
	while (is_digit(nptr[i]))
	{
		ret = ret * 10 + (nptr[i] - 48);
		i++;
	} 
	return ret * sign;
}