#include "libtam.h"

static int is_space(int c)
{
	if((c>=9 && c<=13 )|| c == 32 )
		return 8192;
	return 0;
}

static int is_digit(int c)
{
	if  ( c <='9' && c >= '0')
		return 2048;
	return 0;
}

long ex_atol(char *nptr)
{
	long r;
	long i;
	long s;
	r = 0;
	i = 0;
	s = 1;

	if(nptr[0] == 0)
        return 0;
	while(is_space(nptr[i]))
		i++;
	if (nptr[i] == '+')
	    i++;
	else if (nptr[i] =='-')
	{
		s = -1;
		i++;
	}
	while (is_digit(nptr[i]))
	{
		r = r * 10 + (nptr[i] - 48);
		i++;
	} 
	return r * s;
}