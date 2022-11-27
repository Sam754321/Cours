#include "libtam.h"
#include <stdio.h>
#include <limits.h>

static long long puis(int nb, int puis)
{
	long ret;
	ret =0;

	if(nb && puis >=1)
	{
		ret = nb;
		while(puis > 1)
		{
			ret *= nb;
			puis--;
		}
		return ret;
	}
	return 1;
}

static int checkchar(char str)
{
	
	if(str == ' ' || str == '\n' ||str == '\t' ||str == '-' || str == '+' || str == '\v' )
		return 1;
	return 0;
}

static int checkdigit(char str)
{
	if(str >= 48 && str <= 57)
		return 1;
	return 0;
}

static int lastdigit(char *str ,int i)
{
	while(checkdigit(str[i]))
	{
		i++;
	}
	if(i != 0)
			return (i-1);
	return (i);
}
static long long checknegativ(int x, long long ret)
{
	if(x == -1)
	{
		if(ret == LONG_MIN)
			return LONG_MIN;
		ret *= x;
	}
	return ret;
}


long ex_atol2(char *str)
{
	long long ret;
	int i;
	int j;
	int x;
	
	ret = 0;
	i = 0;
	j = 0;
	x = 0; // nom pas asser explicite
	if(str)
	{
		while(checkchar(str[i]))
		{
			if((str[i] == '-' && !checkdigit(str[i+1])) || (str[i] == '+' && !checkdigit(str[i+1])))
				return 0;
			x = str[i] == '-' ? -1 : 0;
			i++;
		}
		// pas de debug dans le code !
		lastdigit(str, i);
		while(checkdigit(str[i]))
		{
			ret += (str[i] - 48) * puis(10,j);
			i--;
			j++;
		}
		ret = checknegativ(x, ret);	
		return ret;
	}
	return 0;
}