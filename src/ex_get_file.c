#include "libtam.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

static void check_end_str(char *str)
{
	size_t len;

	len = 0;
	if (str)
	{
		len = ex_strlen(str);	
		ex_is_space(str[len-1]) ? str[len-1] = 0 : 0;
		ex_is_space(str[len-2]) ? str[len-2] = 0 : 0;
	}
}

static char *mallo_bufer_read(int siz)
{
	char *retstr;
	if(!(retstr = (char*)malloc(siz)))
		ex_print_error_exit("ERROR MALLOC");
	ex_memset(retstr,11,0);
	return retstr;
}

// indentation
static char *ret_cpy_join_read(char *tempstr, char *tmp_join_str)
{
	char *retstr;

	retstr = NULL;
	if(tmp_join_str)
	{
		retstr = ex_strjoin(tmp_join_str,tempstr);
		free(tmp_join_str);
		check_end_str(retstr);
	}
	else
	{
		retstr = ex_strdup(tempstr);
		check_end_str(retstr);
	}
	return retstr;
}

static void cpy_join_read(char **retstr, char **tempstr, char **tmp_join_str)
{
	if(!(*tmp_join_str))
	{
		*tmp_join_str = ex_strdup(*tempstr);
		*retstr = *tmp_join_str;
	}
	else if(*(tmp_join_str))
	{
		*retstr = ex_strjoin(*tmp_join_str, *tempstr);
		free(*tmp_join_str);
		*tmp_join_str = *retstr;
	}
}


// fix pour la norme
char *close_return(char *tempstr, int f, char *tmp_join_str, char *retstr)
{
	retstr = ret_cpy_join_read(tempstr, tmp_join_str);
	free(tempstr);
	f ? close(f) : 0;
	return retstr;
}

// trop de lignes, fix au dessus
char *ex_get_file(const char *path)
{
	int f;
	int nc;
	char *retstr;
	char *tempstr;
	char *tmp_join_str;

	retstr = NULL;
	tmp_join_str = NULL;
	nc = 1;
	if((f = open(path, O_RDONLY)) == -1)
		ex_print_error_exit("ERROR IN OPEN EX_GET_FILE");
	tempstr = mallo_bufer_read(10001);
	while(nc != 0)
	{
		if((nc = read(f,tempstr,10000))  == -1)
		{
			free(tempstr);
			f ? close(f) : 0;
			ex_print_error_exit("ERROR IN READ EX_GET_FILE");
		}
		tempstr[nc] = '\0';
		if(nc < 10000)
			return close_return(tempstr, f, tmp_join_str, retstr);
		else if(nc == 10000)
			cpy_join_read(&retstr, &tempstr, &tmp_join_str);
	}
	tempstr ? free(tempstr) : 0;
	f ? close(f) : 0;
	return retstr;
}