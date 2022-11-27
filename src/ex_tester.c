#include "libtam.h"
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>

static void exit_error(char *str)
{
    char *ret;

    ret = "Error";
    if(str)
        ret = str;
    ex_putstr(ret);
    ex_putchar('\n');
    exit(1);
}

// ajouté pour la norme
static void print_array_parsed(t_parsed *st_pars, int i, char *str)
{
    while(st_pars->array[i])
    {
        str = ex_ltoa(i+1);
        ex_putstr(str);
        ex_putstr(" : ");
        ex_putstr(st_pars->array[i]);
        ex_putchar('\n');
        free(str);
        i++;
    }
}

// Norme lignes !
static void print_msg(t_list *lst)
{
    t_parsed *st_pars;
    t_list *tmp_lst;
    char *str;

    tmp_lst = lst;
    str = NULL;
    while(tmp_lst)
    {
        st_pars = (t_parsed*)tmp_lst->content;
        if(!st_pars->msg || !st_pars->array)
            exit_error("ERREUR_PARSED_MSG_ARRAY");
        if(st_pars->msg && st_pars->array)
        {
            ex_putstr(st_pars->msg);
            ex_putchar('\n');
            print_array_parsed(st_pars, 0, str);
        }
        tmp_lst = tmp_lst->next;
    }
}

static int check_di_str(char *str)
{
    int i;

    i = 0;
    while(ex_is_space(str[i]))
        i++;
    if(str[i] == '-' || str[i] == '+')
            i++;
	if(str[i] >= 48 && str[i] <= 57)
		return 1;
	return 0;
}

static void print_err_entry(char *str)
{
    printf("%s\n",str);
    if(str)
    {
        ex_putstr("Entrez un nombre de 1 à ");
        ex_putstr(str);
        ex_putchar('\n');
    }
}

static void read_retour(t_parsed *st_pars)
{
    char *ret;
    char * tmp;
    long str_to_long;
    int flag_char;
    
    if (!st_pars || !st_pars->error || !st_pars->array ||!st_pars->success)
        exit_error("Erreur_Parsed_List");
    if(!(ret = (char*)malloc(sizeof(char) * 257))) // mettre la valeur dans un define du .h est plus lisible ex: #define READ_MAX_BUFFER 256, tu alloue avec * READ_MAX_BUFFER + 1
        exit_error("Erreur_Allocation");
    tmp = ex_ltoa(ex_str_array_len((const char**)st_pars->array));
    do{       
        if(!(read(0, ret, 256)))
            exit_error("Erreur_Read");
        flag_char = check_di_str(ret);
        str_to_long = ex_atol(ret);
        if(!flag_char)
            print_err_entry(tmp);
        if(flag_char && str_to_long != st_pars->correct)
        {
            ex_putstr(st_pars->error);
            ex_putchar('\n');
        }
    } while ((str_to_long != st_pars->correct || !flag_char));
    ex_putstr(st_pars->success);
    ex_putchar('\n');
    tmp ? free(tmp) : 0;
    free(ret);
}

void ex_tester(t_list *lst)
{
    if(lst && lst->content)
    {
        print_msg(lst);
        read_retour((t_parsed*)lst->content);       
    }   
}