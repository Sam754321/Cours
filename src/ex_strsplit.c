#include "libtam.h"
#include <stdlib.h>
#include <stdio.h>

static int split(char *str, char c)
{
	int nb;

	nb = 0;
	if (str)
	{
		while(str && *str)
		{
			if(*str == c)
				str++;
			else if (*str != c && *str != 0)
			{
				nb++;
				while(*str != c && *str != 0)
					str++;
			}
		}
	}
	return nb;
}

static void ex_mset(void *p, int size, char c)
{
	int i;
	char *t;

	i = 0;
	t = (char *)p;
	if (!p || size <= 0)
		return;
	while(i <size)
	{
		t[i] = c;
		i++;
	}
}

static char **maloarr(int nb)
{
	char **ret;

	ret = NULL;
	if(!(ret = (char **)malloc(sizeof(char*) *nb + 1)))
		return NULL;
	return ret;
}

static char *malostr(int nb)
{
	char *ret;

	ret = NULL;
	if(!(ret = (char *)malloc(sizeof(char*) *nb +1)))
		return NULL;
	ex_mset(ret,(nb + 1),0);
	return ret;
}

static int ex_len(char *str, char c)
{
	int ret;
	
	ret = 0;
	if(str)
	{	
		while(str[ret] != '\0' && str[ret] != c)
			ret++;
		return ret;
	}
	return 0;
}
//retourne un array d une string diviser par le char envoyer;
char **ex_strsplit(const char *st, char c)
{
	char **retarr;
	int j;
	char *strtostock;
	char* str;
	char *freestr;

	str = ex_strdup(st);
	j = 0;
	strtostock = NULL;
	retarr = NULL;
	freestr = str;
	if( str && c)
	{
		retarr = maloarr(split(str, c));
		while(str && *str)
		{
			if(*str == c)
				str++;
			else if (*str != c && *str != 0)
			{
				strtostock = malostr(ex_len(&(*str),c));
				retarr[j] = strtostock;
				while(*str != c && *str!= 0)
				{
					*strtostock = *str;
					str++;
					strtostock++;
				}
				j++;
			}
		}
	}
	retarr ? retarr[j] = '\0' : 0;
	str ? free(freestr) : 0;
	return retarr;
}