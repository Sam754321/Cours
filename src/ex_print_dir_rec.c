#include "libtam.h"
         
static void print_lst_dir(t_list *tmp_next_lst)
{
    t_content *content_lst;
    char *str;
    char *str2;

    while ( tmp_next_lst )
        {
            content_lst = tmp_next_lst->content;
            str2 = ex_strrchr(content_lst->path, '/');
            if((str2[1] != '.' && str2[2] != '.') || (str2[1] == '.' && str2[2] != '.' && str2[2] != 0))
            {
                ex_putstr(content_lst->stat_array_info[0]);
                ex_putstr(" ");
                ex_putstr(content_lst->stat_array_info[1]);
                ex_putstr(" ");
                ex_putstr(content_lst->stat_array_info[2]);
                ex_putstr(" ");
                ex_putstr(content_lst->stat_array_info[3]);
                ex_putstr(" ");
                str = ex_ltoa(content_lst->len);
                ex_putstr(str);
                ex_putstr(" ");
                ex_putstr(content_lst->stat_array_info[4]);
                ex_putstr(" ");
                ex_putstr(&str2[1]);
                ex_putstr("\n");
                free(str);
            }
            tmp_next_lst = tmp_next_lst->next;
        }
}

static void free_del_content(void *tmp_lst)
{
    t_content *lst;

    lst = (t_content*)tmp_lst;
    if(lst)
    {
        free(lst->path);
        lst->path = NULL;
        lst->len = 0;
        lst->type = 0;
        free(lst);
        tmp_lst = NULL;
        lst = NULL;
    }
}

void ex_print_dir_rec(char *path)
{
    t_list *lst;
    t_list *tmp_next_lst;
    t_content *content_lst;
    char *str;

    if(path)
    {
        ex_putstr(path);
        ex_putstr(":\n");
        if(!(lst = ex_get_dir_list(path)))
                return;
        tmp_next_lst = lst;
        print_lst_dir(tmp_next_lst);
        ex_putstr("\n");
        tmp_next_lst = lst;
        while( tmp_next_lst)
        {
            content_lst = tmp_next_lst->content;
            str = ex_strrchr(content_lst->path, '/');
            if(content_lst->type == 'd' && str[0] != '.' && str[1] !='.')
                ex_print_dir_rec(content_lst->path);
            tmp_next_lst = tmp_next_lst->next;
        }
        ex_list_del_all(&lst, free_del_content);
    }
}