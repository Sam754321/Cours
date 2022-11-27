#include "libtam.h"
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <limits.h>

static int size_nbr(long nb)
{
	int ret;

	ret = 1;
	if(nb < 0 )
	{
		if(nb == LONG_MIN)
		{
			nb = -223372036854775808;
			ret++;
		}
		nb *= -1;
		ret++;
	}
	while(nb >= 9 )
	{
		nb = nb / 10;
		ret++;
	}
	return ret;
}

static void char_to_str(char *str, char c, int reset)
{
	static int i = 0;

	if (reset == 1)
	{
		i = 0;
		return ;
	}
	str[i] = c;
	i++;
}

static 	void nbr_to_char(char *str, long nb)
{
	if(nb < 0)
	{
		char_to_str(str, '-', 0);
		if(nb == LONG_MIN)
		{
			nb = -223372036854775808;
			char_to_str(str, '9', 0);
		}
		nb *= -1;
	}
	if(nb < 10)
	{
		char_to_str(str, nb + 48, 0);
	}
	else
	{
		nbr_to_char(str, nb / 10);
		nbr_to_char(str, nb % 10);
	}
}

char *ex_ltoa(long nb)
{
	char *retstr;
	int i;

	i = size_nbr(nb);
	if(!(retstr = (char*)malloc(i +1)))
		return NULL;
	char_to_str(NULL, 0, 1);
	nbr_to_char(retstr, nb);
	retstr[i] = 0;
	return retstr;
}