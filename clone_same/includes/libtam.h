# ifndef __TEST_H__
# define __TEST_H__

#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/sysmacros.h>

 # define SET_OPTS					1
 # define XOR_OPTS					2
 # define SUPR_OPTS					4
 # define LAST_OPTS					8
 

typedef struct          s_list
{
    void                *content;
    struct s_list       *next;
}                       t_list;

typedef struct s_test
{
    int val;
    char *str;
}              t_test;

typedef struct          s_content
{
    char *path;
    size_t len;
    unsigned char type;
    char **stat_array_info;
}                       t_content;

typedef struct s_parsed
{
    char *msg;
    char *error;
    char *success;
    char **array;
    int correct;
}              t_parsed;

void ex_memset(void *p, unsigned long long size, char c);
char *ex_strdup(const char *str);
char *ex_ltoa(long nb);
long ex_atol2(char *nb);
char *ex_get_file(const char *path);
void ex_memdel(void **p);
void ex_memdel_arr(void ***p);
void ex_putchar(char c);
void ex_putnbr(int nb);
void ex_putstr(char *str);
void ex_ptr(int *nb);
void ex_div_mod(int a, int b, int *div, int *mod);
void ex_div_mod_ptr(int *a, int *b);
unsigned long long ex_strlen(const char *str);
char **ex_strsplit(const char*str,char c);
char *ex_strsub(const char *str, unsigned int start, size_t len);
char *ex_strtrim(const char * str, char *set);
char *ex_strjoin(const char *s1, const char *s2);
char *ex_implode(char **arr, char c);
t_list *ex_listnew(void *content);
void ex_list_push_back(t_list **head, t_list *new);
void ex_list_push_front(t_list **head, t_list *new);
size_t ex_list_size(t_list *list);
t_list *ex_list_last(t_list *list);
char *ex_strchr(const char *str, int c);
char *ex_strrchr(const char *str, int c);
int ex_strcmp(const char *str1, const char *str2);
int ex_strncmp(const char *str1, const char *str2, size_t n);
void *ex_memcpy(const void *dest, const void *src, size_t n);
void *ex_memchr(const void *s, int c, size_t n);
void *ex_memrchr(const void *s, int c, size_t n);
void ex_del_content(void *content);
void ex_list_del_one(t_list *element, void (*del)(void *));
void ex_lstiter(t_list *lst,void (*f)(void*elem));
void ex_list_del_all(t_list **head, void (*del)(void *));
t_list *ex_get_dir_list(char *path);
void ex_tester(t_list *lst);
size_t ex_str_array_len(const char **arr);
long ex_atol( char *nptr);
int ex_is_space(int c);
t_list *ex_parser(char *path);
void ex_print_error_exit(char *str);
void ex_del_free_array(char **arr);
int check_opts(char *str, char *list_option, long *options, int type);
int ex_is_alpha(char c);
int ex_cmp_char_str(char c, char *str);
void ex_print_dir_rec(char *path);
char **array_str_stat_info(struct stat *info);

#endif