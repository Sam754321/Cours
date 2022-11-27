#include "libtam.h"
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/sysmacros.h>

// fais un effort sur l'indentation !
static void check_err(int nb, char *str)
{
    if(nb != 0)
    {
        ex_putnbr(errno);
        ex_putchar(':');
        perror(str);
    }       
    return;
}

// memset peut etre utile ici
static char *malostr(const char *s1, const char *s2)
{
    char * retstr;
    size_t len;

    retstr = NULL;
    len = 0;
    if(s1 && s2)
    {
        len = ex_strlen((char*)s1) + ex_strlen((char*)s2) + 2;
        if(!(retstr = (char *)malloc(sizeof(char) * len))) // + 2 ?
            return NULL;
    }
    else if(s1 && !s2)
    {
        len = ex_strlen((char*)s1) + 2;
        if(!(retstr = (char *)malloc(sizeof(char) * len)))
            return NULL;
    }
    else if(!s1 && s2)
    {
        len = ex_strlen((char*)s2) + 1;
        if(!(retstr = (char *)malloc(sizeof(char) * len)))
            return NULL;
    }
    ex_memset((void *)retstr, len, 0);
    return retstr;
}

static char *join_path(const char *s1, const char *s2)
{
  char * retstr;
  int j;
  int i;

  retstr = NULL;
  i = 0;
  j = 0;
  if(s1 || s2)
  { 
      retstr = malostr(s1, s2);
      if(s1)
      {
           for(i = 0; s1[i] != 0; i++)
                retstr[i] = s1[i];
            if(i > 0 && retstr[i - 1] != '/')
	        {
                retstr[i] = '/';
	            i++;
            }
      }
      if(s2)
      {
          for(j = 0; s2[j] != 0; j++, i++)
                retstr[i] = s2[j];
      }
      retstr[i] = 0;
  }
    return retstr;
}

// SUPPRIME LES DEBUG !

static unsigned char typ_file_stat(struct stat *stat)
{
    char ret;

    ret = 'u';
    if(!stat)
        return 0;
    stat->st_mode & S_IFCHR ? ret = 'c' : 0;
    stat->st_mode & S_IFDIR ? ret = 'd' : 0;
    stat->st_mode & S_IFIFO ? ret = 'f' : 0;
    stat->st_mode & S_IFLNK ? ret = 'l' : 0;
    stat->st_mode & S_IFREG ? ret = 'r' : 0;
    stat->st_mode & S_IFSOCK ? ret = 's': 0;
    stat->st_mode & S_IFBLK ? ret = 'b' : 0;
    // NE PAS LAISSER DE DEBUG
    return ret;
}

static t_content *ex_list_content_new(struct stat *info,char *nam, size_t siz, unsigned char typ)
{
    t_content *retlist;

    retlist = NULL;
    if(nam)
    {
        if(!(retlist = (t_content*)malloc(sizeof(t_content))))
            return NULL;
        retlist->path = ex_strdup(nam);
        retlist->len = siz;
        retlist->type = typ;
        retlist->stat_array_info = array_str_stat_info(info);
    }
    return retlist;
}

static t_list *dir_list_content_list(char *path, struct dirent *dir)
{
    struct stat stat_file;
    t_list *new_lst;
    t_content *new_content;
    char *content_path;

    if(path && dir)
    {
            content_path = join_path(path, dir->d_name);
            if((lstat(content_path, &stat_file) != 0))
                perror("lstat error");
            new_content = ex_list_content_new(&stat_file,content_path, stat_file.st_size, typ_file_stat(&stat_file));
            new_lst = ex_listnew(new_content);
            free(content_path);
    }
    return new_lst;
}

t_list *ex_get_dir_list(char *path)
{
    DIR *dir_opn;
    t_list *lst_directory;
    struct dirent *tab_dir_info;
    t_list **head_lst;

    lst_directory = NULL;
    head_lst = &lst_directory;
    dir_opn = NULL;
    if(path)
    {
        errno = 0;
        dir_opn = opendir(path);

        check_err(errno,"opendir");
        if(errno == 13 || errno == 20 || errno == 2)
            return *head_lst;
        do{
            errno = 0;
            tab_dir_info = readdir(dir_opn);
            check_err(errno,"readdir");
            if(tab_dir_info)
	        {          
                if(!(*head_lst))
                  *head_lst = dir_list_content_list(path, tab_dir_info);
                else
                    ex_list_push_back(head_lst, dir_list_content_list(path, tab_dir_info));
            }
        }while(tab_dir_info);
        check_err(errno, "readdir");
        closedir(dir_opn);
        check_err(errno, "closedir");
    }
    return *head_lst;
}