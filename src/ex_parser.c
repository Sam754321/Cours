#include "libtam.h"

static void pars_in(t_parsed* st_pars, char **tmp_arr)
{
    char *tmp;

    tmp = NULL;
    if(st_pars && tmp_arr && ex_str_array_len((const char**)tmp_arr) == 5)
    {   
        st_pars->msg = ex_strdup(tmp_arr[0]);
        st_pars->success = ex_strdup(tmp_arr[1]);
        st_pars->error = ex_strdup(tmp_arr[2]);
        tmp = ex_strtrim((const char*)tmp_arr[3], "|");
        tmp ? 0 : ex_print_error_exit("ERROR_ARRAY");
        st_pars->array = ex_strsplit(tmp , '#');
        st_pars->correct = (int)ex_atol(tmp_arr[4]);
        tmp ? free(tmp) : 0;
    }
    else
        ex_print_error_exit("ERROR_PARSING_IN");
}

static t_parsed *str_to_st_pars(char *str)
{
    t_parsed *ret_st_pars;
    char **tmp_arr;

    ret_st_pars = NULL;
    tmp_arr = NULL;
    if(str)
    {
        (ret_st_pars = (t_parsed*)malloc(sizeof(t_parsed))) ? 0 : ex_print_error_exit("Erreur_Allocation");
        (tmp_arr = ex_strsplit(str,',')) ? 0 : ex_print_error_exit("Erreur_Split_T_Parsed");
        pars_in(ret_st_pars, tmp_arr);
        if(!ret_st_pars->msg || !ret_st_pars->success || !ret_st_pars->error || !ret_st_pars->array )
                ex_print_error_exit("ERROR_PARSING_IN");
        tmp_arr ? ex_del_free_array(tmp_arr) : 0;
    }
    return ret_st_pars;
}


t_list *ex_parser(char *path)
{
    t_list *ret_lst;
    char **arr_st_pars;
    char **arr_iter_pars;
    char *str_entry;

    ret_lst = NULL;
    if(!path)
        ex_print_error_exit("Erreur_Path");
    str_entry = ex_get_file(path);
    (arr_st_pars = ex_strsplit(str_entry, ';')) ? 0 : ex_print_error_exit("Erreur_Pars_T_List");
    arr_iter_pars = arr_st_pars;
    free(str_entry);
    while(arr_iter_pars && *arr_iter_pars)
    {
        if(!(ret_lst))
            ret_lst = ex_listnew(str_to_st_pars(*arr_iter_pars));
        else
            ex_list_push_back(&ret_lst, ex_listnew(str_to_st_pars(*arr_iter_pars)));
        arr_iter_pars++;
    }
    if(arr_st_pars)
    {
        arr_iter_pars = arr_st_pars;
        while(arr_iter_pars && *arr_iter_pars)
        {
            free(*arr_iter_pars);
            arr_iter_pars++;
        }
        free(arr_st_pars);
    }
    return ret_lst;
}