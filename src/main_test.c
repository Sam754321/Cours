#include "./libtam.h"
#include "./.tam_lib/includes/tamcustom.h"
#include "./colors.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <pwd.h>

static void affiche_bin(unsigned n)
{
    unsigned mask = ~(~0U >> 1);
    unsigned i = 0;

    while (mask > 0)
    {
    	if (i != 0 && i % 4 == 0)
    		ex_putchar(' ');

    	ex_putchar((n & mask) ? '1' : '0');
    	mask >>= 1;
    	++i;
    }

    ex_putchar('\n');
}

static void print_array(char **array)
{
    if (!array)
    {
        printf("NULL\n");
        return ;
    }
    while (array && *array)
    {
        printf("[%s]\n", *array);
        array++;
    }
}

static void del_arr(void **arr)
{
    char **cpyptr;

    cpyptr = (char **)arr;
    if (cpyptr)
    {
        while (*cpyptr)
        {
            free(*cpyptr);
            cpyptr++;
        }
    }
    if (arr)
        free(arr);
}

#ifdef __EX_00__

static void print_ex_00()
{
    char *entry;
    char *expected;
    char *custom;


    printf("%sTest fonction : ex_strsub, code couleur : %s(entrée)%s [expected]%s [custom] %s\n", YELLOW_H, BLUE_H, GREEN_H, RED_H, RESET);
    entry = self_strdup("une phrase normale");
    expected = self_strsub(entry, 4, 6);
    custom = ex_strsub(entry, 4, 6);
    printf("%s(%s): %s[%s]%s <===> %s[%s]%s\n",BLUE_H, entry, GREEN_H, expected, YELLOW_H, RED_H, custom, RESET);
    free(entry);
    entry = self_strdup(NULL);
    free(expected);
    expected = self_strsub(entry, 4, 6);
    free(custom);
    custom = ex_strsub(entry, 4, 6);
    printf("%s(%s): %s[%s]%s <===> %s[%s]%s\n",BLUE_H, entry, GREEN_H, expected, YELLOW_H, RED_H, custom, RESET);
    entry = self_strdup("");
    expected = self_strsub(entry, 4, 6);
    custom = ex_strsub(entry, 4, 6);
    printf("%s(%s): %s[%s]%s <===> %s[%s]%s\n",BLUE_H, entry, GREEN_H, expected, YELLOW_H, RED_H, custom, RESET);
    free(entry);
    entry = self_strdup("         hint         ");
    free(expected);
    expected = self_strsub(entry, 9, 4);
    free(custom);
    custom = ex_strsub(entry, 9, 4);
    printf("%s(%s): %s[%s]%s <===> %s[%s]%s\n",BLUE_H, entry, GREEN_H, expected, YELLOW_H, RED_H, custom, RESET);
    free(entry);
    entry = self_strdup("  test size  ");
    free(expected);
    expected = self_strsub(entry, 7, 20);
    free(custom);
    custom = ex_strsub(entry, 7, 20);
    printf("%s(%s): %s[%s]%s <===> %s[%s]%s\n",BLUE_H, entry, GREEN_H, expected, YELLOW_H, RED_H, custom, RESET);
    free(entry);
    entry = self_strdup("  start max   ");
    free(expected);
    expected = self_strsub(entry, 30, 20);
    free(custom);
    custom = ex_strsub(entry, 30, 20);
    printf("%s(%s): %s[%s]%s <===> %s[%s]%s\n",BLUE_H, entry, GREEN_H, expected, YELLOW_H, RED_H, custom, RESET);
    free(entry);
    entry = self_strdup("effet de bord ?");
    free(expected);
    expected = self_strsub(entry, 14, 20);
    free(custom);
    custom = ex_strsub(entry, 14, 20);
    printf("%s(%s): %s[%s]%s <===> %s[%s]%s\n",BLUE_H, entry, GREEN_H, expected, YELLOW_H, RED_H, custom, RESET);
    free(entry);
    entry = self_strdup("effet de bord 2 ?");
    free(expected);
    expected = self_strsub(entry, 17, 20);
    free(custom);
    custom = ex_strsub(entry, 17, 20);
    printf("%s(%s): %s[%s]%s <===> %s[%s]%s\n",BLUE_H, entry, GREEN_H, expected, YELLOW_H, RED_H, custom, RESET);
    free(entry);
    entry = self_strdup("sub to dup");
    free(expected);
    expected = self_strsub(entry, 0, self_strlen(entry));
    free(custom);
    custom = ex_strsub(entry, 0, self_strlen(entry));
    printf("%s(%s): %s[%s]%s <===> %s[%s]%s\n",BLUE_H, entry, GREEN_H, expected, YELLOW_H, RED_H, custom, RESET);
    free(entry);
    entry = self_strdup(" 1 ");
    free(expected);
    expected = self_strsub(entry, 1, 1);
    free(custom);
    custom = ex_strsub(entry, 1, 1);
    printf("%s(%s): %s[%s]%s <===> %s[%s]%s\n",BLUE_H, entry, GREEN_H, expected, YELLOW_H, RED_H, custom, RESET);
    free(entry);
    free(expected);
    expected = self_strsub("depuis la stack", 7, 2);
    free(custom);
    custom = ex_strsub("depuis la stack", 7, 2);
    printf("%s(%s): %s[%s]%s <===> %s[%s]%s\n",BLUE_H, "depuis la stack", GREEN_H, expected, YELLOW_H, RED_H, custom, RESET);
    printf("\n\n");
    free(expected);
    free(custom);
}

#endif

#ifdef __EX_01__

static void print_ex_01()
{
    char *entry;
    char *expected;
    char *custom;
    char *set = " \f\n\r\t\v";


    printf("%sTest fonction : ex_strtrim, code couleur : %s(entrée)%s [expected]%s [custom] %s\n", YELLOW_H, BLUE_H, GREEN_H, RED_H, RESET);
    entry = self_strdup("          une phrase normale          ");
    expected = self_strtrim(entry);
    custom = ex_strtrim(entry, set);
    printf("%s(%s): %s[%s]%s <===> %s[%s]%s\n",BLUE_H, entry, GREEN_H, expected, YELLOW_H, RED_H, custom, RESET);
    free(entry);
    free(expected);
    free(custom);
    entry = self_strdup(NULL);
    expected = self_strtrim(entry);
    custom = ex_strtrim(entry, set);
    printf("%s(%s): %s[%s]%s <===> %s[%s]%s\n",BLUE_H, entry, GREEN_H, expected, YELLOW_H, RED_H, custom, RESET);
    entry = self_strdup("");
    expected = self_strtrim(entry);
    custom = ex_strtrim(entry, set);
    printf("%s(%s): %s[%s]%s <===> %s[%s]%s\n",BLUE_H, entry, GREEN_H, expected, YELLOW_H, RED_H, custom, RESET);
    free(entry);
    free(expected);
    free(custom);
    entry = self_strdup(" \t \t  les backslashs \n \n       ");
    expected = self_strtrim(entry);
    custom = ex_strtrim(entry, set);
    printf("%s(%s): %s[%s]%s <===> %s[%s]%s\n",BLUE_H, entry, GREEN_H, expected, YELLOW_H, RED_H, custom, RESET);
    free(entry);
    free(expected);
    free(custom);
    entry = self_strdup(" trim                  inutile     ");
    expected = self_strtrim(entry);
    custom = ex_strtrim(entry, set);
    printf("%s(%s): %s[%s]%s <===> %s[%s]%s\n",BLUE_H, entry, GREEN_H, expected, YELLOW_H, RED_H, custom, RESET);
    free(entry);
    free(expected);
    free(custom);
    entry = self_strdup("trim to dup");
    expected = self_strtrim(entry);
    custom = ex_strtrim(entry, set);
    printf("%s(%s): %s[%s]%s <===> %s[%s]%s\n",BLUE_H, entry, GREEN_H, expected, YELLOW_H, RED_H, custom, RESET);
    free(entry);
    free(expected);
    free(custom);
    entry = self_strdup("?       effet de bord       ?");
    expected = self_strtrim(entry);
    custom = ex_strtrim(entry, set);
    printf("%s(%s): %s[%s]%s <===> %s[%s]%s\n",BLUE_H, entry, GREEN_H, expected, YELLOW_H, RED_H, custom, RESET);
    free(entry);
    free(expected);
    free(custom);
    entry = self_strdup(" 1 ");
    expected = self_strtrim(entry);
    custom = ex_strtrim(entry, set);
    printf("%s(%s): %s[%s]%s <===> %s[%s]%s\n",BLUE_H, entry, GREEN_H, expected, YELLOW_H, RED_H, custom, RESET);
    free(entry);
    free(expected);
    free(custom);
    expected = self_strtrim(" depuis la stack ");
    custom = ex_strtrim(" depuis la stack ",set);
    printf("%s(%s): %s[%s]%s <===> %s[%s]%s\n",BLUE_H, " depuis la stack ", GREEN_H, expected, YELLOW_H, RED_H, custom, RESET);
    printf("\n\n");
    free(expected);
    free(custom);
}

#endif

#ifdef __EX_02__

static void print_ex_02()
{
    char *entry;
    char **expected;
    char **custom;


    printf("%sTest fonction : ex_strsplit, code couleur : %s(entrée)%s [expected]%s [custom] %s\n", YELLOW_H, BLUE_H, GREEN_H, RED_H, RESET);
    entry = self_strdup("Une phrase avec quelques mots.");
    expected = self_strsplit(entry, ' ');
    custom = ex_strsplit(entry, ' ');
    printf("%s(%s): %s\n", BLUE_H, entry, GREEN_H);
    print_array(expected);
    printf("%s <===> %s\n", YELLOW_H, RED_H);
    print_array(custom);
    printf("%s\n", RESET);
    free(entry);
    del_arr((void **)expected);
    del_arr((void **)custom);

    entry = self_strdup(NULL);
    expected = self_strsplit(entry, ' ');
    custom = ex_strsplit(entry, ' ');
    printf("%s(%s): %s\n", BLUE_H, entry, GREEN_H);
    print_array(expected);
    printf("%s <===> %s\n", YELLOW_H, RED_H);
    print_array(custom);
    printf("%s\n", RESET);
    free(entry);
    del_arr((void **)expected);
    del_arr((void **)custom);

    entry = self_strdup("");
    expected = self_strsplit(entry, ' ');
    custom = ex_strsplit(entry, ' ');
    printf("%s(%s): %s\n", BLUE_H, entry, GREEN_H);
    print_array(expected);
    printf("%s <===> %s\n", YELLOW_H, RED_H);
    print_array(custom);
    printf("%s\n", RESET);
    free(entry);
    del_arr((void **)expected);
    del_arr((void **)custom);

    entry = self_strdup(" Une   phrase   avec   plein d'interference     ! ");
    expected = self_strsplit(entry, ' ');
    custom = ex_strsplit(entry, ' ');
    printf("%s(%s): %s\n", BLUE_H, entry, GREEN_H);
    print_array(expected);
    printf("%s <===> %s\n", YELLOW_H, RED_H);
    print_array(custom);
    printf("%s\n", RESET);
    free(entry);
    del_arr((void **)expected);
    del_arr((void **)custom);



    entry = self_strdup(" Une   phrase   avec   plein d'interference     ! split sur le caractere 'a' ");
    expected = self_strsplit(entry, 'a');
    custom = ex_strsplit(entry, 'a');
    printf("%s(%s): %s\n", BLUE_H, entry, GREEN_H);
    print_array(expected);
    printf("%s <===> %s\n", YELLOW_H, RED_H);
    print_array(custom);
    printf("%s\n", RESET);
    free(entry);
    del_arr((void **)expected);
    del_arr((void **)custom);

    entry = self_strdup(" effet de bord ");
    expected = self_strsplit(entry, ' ');
    custom = ex_strsplit(entry, ' ');
    printf("%s(%s): %s\n", BLUE_H, entry, GREEN_H);
    print_array(expected);
    printf("%s <===> %s\n", YELLOW_H, RED_H);
    print_array(custom);
    printf("%s\n", RESET);
    free(entry);
    del_arr((void **)expected);
    del_arr((void **)custom);


    entry = self_strdup(" 1 ");
    expected = self_strsplit(entry, ' ');
    custom = ex_strsplit(entry, ' ');
    printf("%s(%s): %s\n", BLUE_H, entry, GREEN_H);
    print_array(expected);
    printf("%s <===> %s\n", YELLOW_H, RED_H);
    print_array(custom);
    printf("%s\n", RESET);
    free(entry);
    del_arr((void **)expected);
    del_arr((void **)custom);


    entry = self_strdup("rien");
    expected = self_strsplit(entry, ' ');
    custom = ex_strsplit(entry, ' ');
    printf("%s(%s): %s\n", BLUE_H, entry, GREEN_H);
    print_array(expected);
    printf("%s <===> %s\n", YELLOW_H, RED_H);
    print_array(custom);
    printf("%s\n", RESET);
    free(entry);
    del_arr((void **)expected);
    del_arr((void **)custom);

    expected = self_strsplit(" depuis la stack et le tableau va etre relativement long,  avec  quelques  interferences 1   2       3    4 5   & é ' ( - è _  ç à ", ' ');
    custom = ex_strsplit(" depuis la stack et le tableau va etre relativement long,  avec  quelques  interferences 1   2       3    4 5   & é ' ( - è _  ç à ", ' ');
    printf("%s(%s): %s\n", BLUE_H, " depuis la stack et le tableau va etre relativement long,  avec  quelques  interferences 1   2       3    4 5   & é ' ( - è _  ç à ", GREEN_H);
    print_array(expected);
    printf("%s <===> %s\n", YELLOW_H, RED_H);
    print_array(custom);
    printf("%s\n", RESET);
    del_arr((void **)expected);
    del_arr((void **)custom);

    printf("\n\n");
}
#endif

#ifdef __EX_03__

static void print_ex_03()
{
    char *entry;
    char *entry2;
    char *expected;
    char *custom;


    printf("%sTest fonction : ex_strjoin, code couleur : %s(entrée)%s [expected]%s [custom] %s\n", YELLOW_H, BLUE_H, GREEN_H, RED_H, RESET);
    entry = self_strdup("une");
    entry2 = self_strdup("phrase");
    expected = self_strjoin(entry, entry2);
    custom = ex_strjoin(entry, entry2);
    printf("%s([%s]  [%s]): %s[%s]%s <===> %s[%s]%s\n",BLUE_H, entry, entry2,  GREEN_H, expected, YELLOW_H, RED_H, custom, RESET);
    free(entry);
    free(entry2);
    free(expected);
    free(custom);


    printf("%sTest fonction : ex_strjoin, code couleur : %s(entrée)%s [expected]%s [custom] %s\n", YELLOW_H, BLUE_H, GREEN_H, RED_H, RESET);
    entry = self_strdup("");
    entry2 = self_strdup("");
    expected = self_strjoin(entry, entry2);
    custom = ex_strjoin(entry, entry2);
    printf("%s([%s]  [%s]): %s[%s]%s <===> %s[%s]%s\n",BLUE_H, entry, entry2,  GREEN_H, expected, YELLOW_H, RED_H, custom, RESET);
    free(entry);
    free(entry2);
    free(expected);
    free(custom);

    printf("%sTest fonction : ex_strjoin, code couleur : %s(entrée)%s [expected]%s [custom] %s\n", YELLOW_H, BLUE_H, GREEN_H, RED_H, RESET);
    entry = self_strdup("une");
    entry2 = self_strdup(NULL);
    expected = self_strjoin(entry, entry2);
    custom = ex_strjoin(entry, entry2);
    printf("%s([%s]  [%s]): %s[%s]%s <===> %s[%s]%s\n",BLUE_H, entry, entry2,  GREEN_H, expected, YELLOW_H, RED_H, custom, RESET);
    free(entry);
    free(entry2);
    free(expected);
    free(custom);

    printf("%sTest fonction : ex_strjoin, code couleur : %s(entrée)%s [expected]%s [custom] %s\n", YELLOW_H, BLUE_H, GREEN_H, RED_H, RESET);
    entry = self_strdup(NULL);
    entry2 = self_strdup("phrase");
    expected = self_strjoin(entry, entry2);
    custom = ex_strjoin(entry, entry2);
    printf("%s([%s]  [%s]): %s[%s]%s <===> %s[%s]%s\n",BLUE_H, entry, entry2,  GREEN_H, expected, YELLOW_H, RED_H, custom, RESET);
    free(entry);
    free(entry2);
    free(expected);
    free(custom);

    printf("%sTest fonction : ex_strjoin, code couleur : %s(entrée)%s [expected]%s [custom] %s\n", YELLOW_H, BLUE_H, GREEN_H, RED_H, RESET);
    entry = self_strdup(NULL);
    entry2 = self_strdup(NULL);
    expected = self_strjoin(entry, entry2);
    custom = ex_strjoin(entry, entry2);
    printf("%s([%s]  [%s]): %s[%s]%s <===> %s[%s]%s\n",BLUE_H, entry, entry2,  GREEN_H, expected, YELLOW_H, RED_H, custom, RESET);
    free(entry);
    free(entry2);
    free(expected);
    free(custom);

    printf("%sTest fonction : ex_strjoin, code couleur : %s(entrée)%s [expected]%s [custom] %s\n", YELLOW_H, BLUE_H, GREEN_H, RED_H, RESET);
    entry = self_strdup("une premier phrase avec ");
    entry2 = self_strdup("une deuxieme phrase");
    expected = self_strjoin(entry, entry2);
    custom = ex_strjoin(entry, entry2);
    printf("%s([%s]  [%s]): %s[%s]%s <===> %s[%s]%s\n",BLUE_H, entry, entry2,  GREEN_H, expected, YELLOW_H, RED_H, custom, RESET);
    free(entry);
    free(entry2);
    free(expected);
    free(custom);
    

    printf("%sTest fonction : ex_strjoin, code couleur : %s(entrée)%s [expected]%s [custom] %s\n", YELLOW_H, BLUE_H, GREEN_H, RED_H, RESET);
    entry = self_strdup("1");
    entry2 = self_strdup(" ");
    expected = self_strjoin(entry, entry2);
    custom = ex_strjoin(entry, entry2);
    printf("%s([%s]  [%s]): %s[%s]%s <===> %s[%s]%s\n",BLUE_H, entry, entry2,  GREEN_H, expected, YELLOW_H, RED_H, custom, RESET);
    free(entry);
    free(entry2);
    free(expected);
    free(custom);

    printf("%sTest fonction : ex_strjoin, code couleur : %s(entrée)%s [expected]%s [custom] %s\n", YELLOW_H, BLUE_H, GREEN_H, RED_H, RESET);
    entry2 = self_strdup("heap");
    expected = self_strjoin("stack ", entry2);
    custom = ex_strjoin("stack ", entry2);
    printf("%s([%s]  [%s]): %s[%s]%s <===> %s[%s]%s\n",BLUE_H, "stack ", entry2,  GREEN_H, expected, YELLOW_H, RED_H, custom, RESET);
    free(entry2);
    free(expected);
    free(custom);

    printf("%sTest fonction : ex_strjoin, code couleur : %s(entrée)%s [expected]%s [custom] %s\n", YELLOW_H, BLUE_H, GREEN_H, RED_H, RESET);
    expected = self_strjoin("stack ", "stack");
    custom = ex_strjoin("stack ", "stack");
    printf("%s([%s]  [%s]): %s[%s]%s <===> %s[%s]%s\n",BLUE_H, "stack ", "stack",  GREEN_H, expected, YELLOW_H, RED_H, custom, RESET);
    free(expected);
    free(custom);

    printf("\n\n");
}
#endif

#ifdef __EX_04__

static void print_ex_04()
{
    char **entry;
    char *expected;
    char *custom;


    printf("%sTest fonction : ex_implode, code couleur : %s(entrée)%s [expected]%s [custom] %s\n", YELLOW_H, BLUE_H, GREEN_H, RED_H, RESET);
    entry = self_strsplit("une phrase normale", ' ');
    expected = self_implode(entry, ' ');
    custom = ex_implode(entry, ' ');
    printf("%s", BLUE_H);
    print_array(entry);
    printf("%s[%s]%s <===> %s[%s]%s\n", GREEN_H, expected, YELLOW_H, RED_H, custom, RESET);
    del_arr((void **)entry);
    free(expected);
    free(custom);


    //entry = self_strsplit("une phrase normale", ' ');
    entry = NULL;
    expected = self_implode(entry, ' ');
    custom = ex_implode(entry, ' ');
    printf("%s", BLUE_H);
    print_array(entry);
    printf("%s[%s]%s <===> %s[%s]%s\n", GREEN_H, expected, YELLOW_H, RED_H, custom, RESET);
    //del_arr((void **)entry);
    free(expected);
    free(custom);

    entry = self_strsplit("", ' ');
    expected = self_implode(entry, ' ');
    custom = ex_implode(entry, ' ');
    printf("%s", BLUE_H);
    print_array(entry);
    printf("%s[%s]%s <===> %s[%s]%s\n", GREEN_H, expected, YELLOW_H, RED_H, custom, RESET);
    del_arr((void **)entry);
    free(expected);
    free(custom);


    entry = self_strsplit("une phrase que l'on recompose avec des tab", ' ');
    expected = self_implode(entry, '\t');
    custom = ex_implode(entry, '\t');
    printf("%s", BLUE_H);
    print_array(entry);
    printf("%s[%s]%s <===> %s[%s]%s\n", GREEN_H, expected, YELLOW_H, RED_H, custom, RESET);
    del_arr((void **)entry);
    free(expected);
    free(custom);


    entry = self_strsplit("1", ' ');
    expected = self_implode(entry, '\t');
    custom = ex_implode(entry, '\t');
    printf("%s", BLUE_H);
    print_array(entry);
    printf("%s[%s]%s <===> %s[%s]%s\n", GREEN_H, expected, YELLOW_H, RED_H, custom, RESET);
    del_arr((void **)entry);
    free(expected);
    free(custom);

    char *tabstack[6] = {"un", "tableau", "sur", "la", "stack", NULL};
    printf("%s", BLUE_H);
    expected = self_implode(tabstack, ' ');
    custom = ex_implode(tabstack, ' ');
    print_array(tabstack);
    printf("%s[%s]%s <===> %s[%s]%s\n", GREEN_H, expected, YELLOW_H, RED_H, custom, RESET);
    //del_arr((void **)entry);
    free(expected);
    free(custom);

    entry = self_strsplit("une phrase que l'on recompose sans spécifier un char", ' ');
    expected = self_implode(entry, '\0');
    custom = ex_implode(entry, '\0');
    printf("%s", BLUE_H);
    print_array(entry);
    printf("%s[%s]%s <===> %s[%s]%s\n", GREEN_H, expected, YELLOW_H, RED_H, custom, RESET);
    del_arr((void **)entry);
    free(expected);
    free(custom);

    printf("\n\n");
}
#endif

#ifdef __EX_05__

static void print_ex_05()
{
    t_list *expected;
    t_list *custom;
    void    *content;
    t_test stru;

    expected = NULL;
    custom = NULL;
    printf("%sTest fonction : ex_listnew, code couleur : %s(entrée)%s [expected]%s [custom] %s\n", YELLOW_H, BLUE_H, GREEN_H, RED_H, RESET);
    content = self_strdup("bonjour");
    expected = (t_list *)self_listnew((void *)content);
    custom = ex_listnew((void *)content);
    printf("%saddress must not be null/nil : %s%p\n",GREEN_H, RED_H, expected);
    printf("%s[%s && %p]%s <===> %s[%s && %p]%s\n\n", GREEN_H, (char *)expected->content, expected->next, YELLOW_H, RED_H, (char *)custom->content, custom->next, RESET);
    free(content);
    free(expected);
    free(custom);
    content = NULL;
    expected = NULL;
    custom = NULL;

    expected = NULL;
    custom = NULL;
    stru.val = 1337;
    stru.str = "test"; 
    expected = (t_list *)self_listnew((void *)&stru);
    custom = ex_listnew((void *)&stru);
    printf("%saddress must not be null/nil : %s%p\n",GREEN_H, RED_H, expected);
    printf("%s[%s && %d && %p]%s <===> %s[%s && %d && %p]%s\n", GREEN_H, ((t_test *)expected->content)->str,((t_test *)expected->content)->val, expected->next, YELLOW_H, RED_H, ((t_test *)custom->content)->str,((t_test *)expected->content)->val, custom->next, RESET);
    stru.str = "changed";
    printf("%s[%s && %d && %p]%s <===> %s[%s && %d && %p]%s\n", GREEN_H, ((t_test *)expected->content)->str,((t_test *)expected->content)->val, expected->next, YELLOW_H, RED_H, ((t_test *)custom->content)->str,((t_test *)expected->content)->val, custom->next, RESET);
    free(content);
    free(expected);
    free(custom);
    expected = NULL;
    custom = NULL;


    printf("\n\n");
     
 
}
#endif

#ifdef __EX_06__

static void print_ex_06()
{
    t_list *link2;
    t_list *link;
    t_list **head;

    link = NULL;
    link2 = NULL;
    link = (t_list *)self_listnew(NULL);
    head = &link;
    link2 = (t_list *)self_listnew(NULL);
    printf("%sTest fonction : ex_list_push_back, code couleur : %s(entrée)%s [expected]%s [custom] %s\n", YELLOW_H, BLUE_H, GREEN_H, RED_H, RESET);
    printf("%sAdd a link\n%s", YELLOW_H, RESET);
    printf("%saddress must not be null/nil : %s%p%s\n",GREEN_H, RED_H, *head, RESET);
    printf("address before call : *head : %p, (*head)->next : %p, link to add : %p\n", *head, (*head)->next, link2);
    ex_list_push_back(head, link2);
    printf("%s*head==>(*head)->next   %s%p ==> %p %s<===>%s %p ==> %p%s\n\n",BLUE_H, GREEN_H, link, link2, YELLOW_H, RED_H, *head, (*head)->next, RESET);
    free(link);
    free(link2);

    link = NULL;
    link2 = NULL;
    link = (t_list *)self_listnew(NULL);
    head = &link;
    link2 = (t_list *)self_listnew(NULL);
    printf("%sAdd a link that is already pointed by head (error)\n%s", YELLOW_H, RESET);
    printf("%saddress must not be null/nil : %s%p%s\n",GREEN_H, RED_H, *head, RESET);
    printf("address before call : *head : %p, (*head)->next : %p, link to add : %p\n", *head, (*head)->next, link);
    ex_list_push_back(head, link);
    printf("%s*head==>(*head)->next   %s%p ==> %p %s<===>%s %p ==> %p%s\n\n",BLUE_H, GREEN_H, link, NULL, YELLOW_H, RED_H, *head, (*head)->next, RESET);
    free(link);
    free(link2);

    link = NULL;
    link2 = NULL;
    link = (t_list *)self_listnew(NULL);
    head = NULL;
    link2 = (t_list *)self_listnew(NULL);
    printf("%sAdd a link to NULL (error)\n%s", YELLOW_H, RESET);
    printf("%smust not segfault%s\n", GREEN_H, RESET);
    ex_list_push_back(head, link);
    printf("%sOK%s\n", RED_H, RESET);
    free(link);
    free(link2);


    printf("\n\n");
}

#endif

#ifdef __EX_07__

static void print_ex_07()
{
    t_list *link2;
    t_list *link;
    t_list **head;
    t_list *tmp;
    t_list *tmp2;

    link = NULL;
    link2 = NULL;
    link = (t_list *)self_listnew(NULL);
    head = &link;
    link2 = (t_list *)self_listnew(NULL);
    tmp = link;
    printf("%sTest fonction : ex_list_push_front, code couleur : %s(entrée)%s [expected]%s [custom] %s\n", YELLOW_H, BLUE_H, GREEN_H, RED_H, RESET);
    printf("%sAdd a link\n%s", YELLOW_H, RESET);
    printf("%saddress must not be null/nil : %s%p%s\n",GREEN_H, RED_H, *head, RESET);
    printf("address before call : *head : %p, (*head)->next : %p, link to add : %p\n", *head, (*head)->next, link2);
    ex_list_push_front(head, link2);
    printf("%s*head==>(*head)->next   %s%p ==> %p %s<===>%s %p ==> %p%s\n\n",BLUE_H, GREEN_H, link, tmp, YELLOW_H, RED_H, *head, (*head)->next, RESET);
    tmp = *head;
    while(tmp)
    {
        tmp2 = tmp->next;
        free(tmp);
        tmp = tmp2; 
    }


    link = NULL;
    link2 = NULL;
    link = (t_list *)self_listnew(NULL);
    head = &link;
    link2 = (t_list *)self_listnew(NULL);
    tmp = link;
    printf("%sTest fonction : ex_list_push_front, code couleur : %s(entrée)%s [expected]%s [custom] %s\n", YELLOW_H, BLUE_H, GREEN_H, RED_H, RESET);
    printf("%sAdd a link that is already pointed by head (error)\n%s", YELLOW_H, RESET);
    printf("%saddress must not be null/nil : %s%p%s\n",GREEN_H, RED_H, *head, RESET);
    printf("address before call : *head : %p, (*head)->next : %p, link to add : %p\n", *head, (*head)->next, link);
    ex_list_push_front(head, link);
    printf("%s*head==>(*head)->next   %s%p ==> %p %s<===>%s %p ==> %p%s\n\n",BLUE_H, GREEN_H, link, NULL, YELLOW_H, RED_H, *head, (*head)->next, RESET);
    tmp = *head;
    while(tmp)
    {
        tmp2 = tmp->next;
        free(tmp);
        tmp = tmp2; 
    }
    free(link2);

    link = NULL;
    link2 = NULL;
    link = (t_list *)self_listnew(NULL);
    head = NULL;
    link2 = (t_list *)self_listnew(NULL);
    printf("%sAdd a link to NULL (error)\n%s", YELLOW_H, RESET);
    printf("%smust not segfault%s\n", GREEN_H, RESET);
    ex_list_push_front(head, link);
    printf("%sOK%s\n", RED_H, RESET);
    free(link);
    free(link2);


    printf("\n\n");
}

#endif

#ifdef __EX_08__

static void print_ex_08()
{
    t_list *link;
    t_list *tmp;
    t_list *tmp2;
    t_list **head;
    size_t self;
    size_t custom;
    size_t len;

    link = NULL;
    printf("%sTest fonction : ex_list_size, code couleur : %s(entrée)%s [expected]%s [custom] %s\n", YELLOW_H, BLUE_H, GREEN_H, RED_H, RESET);
    self = self_list_size((t_slist *)link);
    custom = ex_list_size(link);
    printf("%s[%ld]%s <===> %s[%ld]%s\n", GREEN_H, self, YELLOW_H, RED_H, custom, RESET);
    tmp = link;
    while(tmp)
    {
        tmp2 = tmp->next;
        free(tmp);
        tmp = tmp2; 
    }

    link = NULL;
    len = 10;
    head = &link;
    while (len--)
        self_list_push_back((t_slist**)head, self_listnew(NULL));
    self = self_list_size((t_slist *)link);
    custom = ex_list_size(link);
    printf("%s[%ld]%s <===> %s[%ld]%s\n", GREEN_H, self, YELLOW_H, RED_H, custom, RESET);
    tmp = link;
    while(tmp)
    {
        tmp2 = tmp->next;
        free(tmp);
        tmp = tmp2; 
    }


    link = NULL;
    len = 30;
    head = &link;
    while (len--)
        self_list_push_back((t_slist**)head, self_listnew(NULL));
    self = self_list_size((t_slist *)link);
    custom = ex_list_size(link);
    printf("%s[%ld]%s <===> %s[%ld]%s\n", GREEN_H, self, YELLOW_H, RED_H, custom, RESET);
    tmp = link;
    while(tmp)
    {
        tmp2 = tmp->next;
        free(tmp);
        tmp = tmp2; 
    }



    printf("\n\n");
}

#endif

#ifdef __EX_09__

static void print_ex_09()
{
    t_list *link;
    t_list *tmp;
    t_list *tmp2;
    t_list **head;
    t_slist *self;
    t_list *custom;
    size_t len;

    link = NULL;
    printf("%sTest fonction : ex_list_last, code couleur : %s(entrée)%s [expected]%s [custom] %s\n", YELLOW_H, BLUE_H, GREEN_H, RED_H, RESET);
    self = self_list_last(NULL);
    custom = ex_list_last(NULL);    
    printf("%s[%p]%s <===> %s[%p]%s\n", GREEN_H, self, YELLOW_H, RED_H, custom, RESET);
    tmp = link;
    while(tmp)
    {
        tmp2 = tmp->next;
        free(tmp);
        tmp = tmp2; 
    }

    link = NULL;
    len = 10;
    head = &link;
    while (len--)
        self_list_push_back((t_slist**)head, self_listnew(NULL));
    self = self_list_last((t_slist *)link);
    custom = ex_list_last(link);
    printf("%sfirst : %p %s[%p]%s <===> %s[%p]%s\n",BLUE_H, link, GREEN_H, self, YELLOW_H, RED_H, custom, RESET);
    tmp = link;
    while(tmp)
    {
        tmp2 = tmp->next;
        free(tmp);
        tmp = tmp2; 
    }


        link = NULL;
    len = 30;
    head = &link;
    while (len--)
        self_list_push_back((t_slist**)head, self_listnew(NULL));
    self = self_list_last((t_slist *)link);
    custom = ex_list_last(link);
    printf("%sfirst : %p %s[%p]%s <===> %s[%p]%s\n",BLUE_H, link, GREEN_H, self, YELLOW_H, RED_H, custom, RESET);
    tmp = link;
    while(tmp)
    {
        tmp2 = tmp->next;
        free(tmp);
        tmp = tmp2; 
    }



    printf("\n\n");
}

#endif

void print_ex_00();
void print_ex_01();
void print_ex_02();
void print_ex_03();
void print_ex_04();
void print_ex_05();
void print_ex_06();
void print_ex_07();
void print_ex_08();
void print_ex_09();

int main(int ac, char **av) 
{
    if (ac <= 1)
    {
        printf("not enough args, usage: ./a.out --all || ./a.out [1-10]");
    }
    else if (strcmp(av[1], "--all") == 0)
    {
        #ifdef __EX_00__
            print_ex_00();
        # endif

        #ifdef __EX_01__
            print_ex_01();
        # endif

        #ifdef __EX_02__
            print_ex_02();
        # endif

        #ifdef __EX_03__
            print_ex_03();
        # endif

        #ifdef __EX_04__
            print_ex_04();
        # endif

        #ifdef __EX_05__
            print_ex_05();
        # endif

        #ifdef __EX_06__
            print_ex_06();
        # endif

        #ifdef __EX_07__
            print_ex_07();
        # endif

        #ifdef __EX_08__
            print_ex_08();
        # endif

        #ifdef __EX_09__
            print_ex_09();
        # endif

    } else 
    {
        int nb_ex;

        nb_ex = atoi(av[1]);
        if (nb_ex == 1)
        {
            #ifdef __EX_00__
                print_ex_00();
            # endif
        }
        else if (nb_ex == 2)
        {
            #ifdef __EX_01__
                print_ex_01();
            # endif
        }
        else if (nb_ex == 3)
        {
            #ifdef __EX_02__
                print_ex_02();
            # endif
        }
        else if (nb_ex == 4)
        {
            #ifdef __EX_03__
                print_ex_03();
            # endif
        }
        else if (nb_ex == 5)
        {
            #ifdef __EX_04__
                print_ex_04();
            # endif
        }
        else if (nb_ex == 6)
        {
            #ifdef __EX_05__
                print_ex_05();
            # endif
        }
        else if (nb_ex == 7)
        {
            #ifdef __EX_06__
                print_ex_06();
            # endif
        }
        else if (nb_ex == 8)
        {
            #ifdef __EX_07__
                print_ex_07();
            # endif
        }
        else if (nb_ex == 9)
        {
            #ifdef __EX_08__
                print_ex_08();
            # endif
        }
        else if (nb_ex == 10)
        {
            #ifdef __EX_09__
                print_ex_09();
            # endif
        }
    }
ex_strchr("un deux trois quatre cinq six sept huit neuf", 'z');
ex_strrchr("un deux trois quatre cinq six sept huit neuf", 'z');
printf("%p\n",ex_strchr("un deux trois quatre cinq six sept huit neuf", 'z'));
printf("%p\n",strchr("un deux trois quatre cinq six sept huit neuf", 'z'));
printf("%s\n",ex_strrchr("un deux trois quatre cinq six sept huit neuf", 'q'));
printf("%s\n",ex_strchr("un deux trois quatre cinq six sept huit neuf", 'x'));
printf("%s\n",strchr("un deux trois quatre cinq six sept huit neuf", 'q'));
printf("%s\n",strrchr("un deux trois quatre cinq six sept huit neuf", 'q'));
printf("%s\n",ex_strchr("un deux trois quatre cinq six sept huit neufz", 'z'));
printf("%s\n",ex_strrchr("zn deux trois quatre cinq six sept huit neuf", 'z'));
printf("%p\n",ex_strchr(NULL, 'z'));
printf("%p\n",ex_strrchr(NULL, 'z'));
printf("%p\n",strchr("un deux trois quatre cinq six sept huit neuf", '\0'));
printf("%p\n",ex_strchr("un deux trois quatre cinq six sept huit neuf", '\0'));
printf("%p\n",ex_strrchr("un deux trois quatre cinq six sept huit neuf", '\0'));
printf("%p\n",strchr("un deux trois quatre cinq six sept huit neuf", 'z'));
printf("%p\n",strrchr("un deux trois quatre cinq six sept huit neuf", 'z'));
printf("%p\n",ex_strrchr("un deux trois quatre cinq six sept huit neuf", '\0'));
printf("%d__cmp\n",strcmp("az",""));
printf("%d__cmp\n",ex_strcmp("az",""));
printf("%d__cmp\n",strncmp("azerty","azertyy",1500));
printf("%d__cmp\n",ex_strncmp("azerty","azertyy",1500));
void *tmpstrr;
tmpstrr = malloc(7);
ex_memcpy(tmpstrr,"wxcvbn", 6);
printf("%s___\n",(char*)tmpstrr);
printf("%s___\n",(char*)ex_memchr("zun deux trois quatre cinqz",'z',50));
printf("%s___\n",(char*)memchr("unz deux trois quatre cinq",'z',50));
printf("%s___\n",(char*)ex_memrchr("un deux trois quatre cinq",'z',27));
free(tmpstrr);

t_list *lst;
t_list **headlst;
int i;
lst = (ex_listnew( ex_strdup("un deux trois")));
headlst = &lst;

for(i = 0; i < 10 ; i++)
{
    ex_list_push_back(headlst,((ex_listnew( ex_strdup("un deux trois")))));
}
for(i = 0; i < 10 ; i++)
{
    ex_list_push_front(headlst,((ex_listnew( ex_strdup("un deux trois")))));
}
 printf("sizelst__%ld\n",ex_list_size(*headlst));

void print_all(void *content)
{
    t_list *tmp;
    tmp = (t_list*)content;
    printf("path : %s\n", (char*)tmp);
}
void del_all(void *content)
{
    char *tmp;
    tmp = (char*)content;
    free(tmp);
}

void print_all_ls(void *content)
{
    t_content *tmp;
    tmp = (t_content*)content;
    char *strr;

    if(tmp)
       { strr = ex_strrchr(tmp->path,'/');
        if(strr && strr[1])
            strr = &strr[1];
        printf("path : [ %s ]  size {%ld}  type {%c}\n", tmp->path, tmp->len, tmp->type);
        printf("[ %s ]  \n",strr);
        }
    else
    printf("non content\n");
}
void del_all_ls(void *content)
{
    t_content *tmp;
    tmp = (t_content*)content;

    if(tmp)
    {
        free(tmp->path);
        tmp->path = NULL;
        free(tmp);
        tmp = NULL;
    }   
}

// void del_all_content(void *content)
// {
//     t_list *tmp;
//     tmp = (t_list*)content;
//     free(tmp);
// }
ex_lstiter(*headlst, print_all);
// ex_list_del_one(ex_list_last(*headlst),del_all);

ex_list_del_all(headlst,del_all);
lst = ex_get_dir_list("/");
*headlst = lst;

ex_lstiter(*headlst,print_all_ls);
 printf("sizelst__%ld\n",ex_list_size(*headlst));
ex_list_del_all(headlst,del_all_ls);

lst = NULL;
headlst = &lst;
t_parsed *pars_lst;
char **arr_test;
arr_test = (char**)malloc(sizeof(char*) *11);

for(i = 0; i < 10 ; i++)
{
   arr_test[i] = "world";
}
arr_test[i] = 0;

pars_lst = (t_parsed*)malloc(sizeof(t_parsed));
pars_lst->msg = "hello", pars_lst->array = arr_test ,pars_lst->error = "ESSAYE ENCORE", pars_lst->success = "BRAVO", pars_lst->correct = 1   ;

for(i = 0; i < 10 ; i++)
{
    ex_list_push_back(headlst,((ex_listnew(pars_lst))));
}
void del_all_pars(void *content)
{
    t_parsed *tmp;
    tmp = (t_parsed*)content;
    if (tmp)
        return;
}
void del_all_pars2(void *content)
{
    t_parsed *tmp;
    char **tmp_arr;
    tmp = (t_parsed*)content;
    if (tmp)
    {
        free(tmp->msg);
        tmp->msg = NULL;
        free(tmp->error);
        tmp->error = NULL;
        free(tmp->success);
        tmp->success = NULL;
        tmp_arr = tmp->array;
        while(tmp_arr && *tmp_arr)
        {
            free(*tmp_arr);
            *tmp_arr = NULL;
            tmp_arr++;
        }
        free(tmp->array);
        free(tmp);
    }
}
// ex_tester(*headlst);
free(pars_lst);
free(arr_test);
ex_list_del_all(headlst,del_all_pars);

t_list *lst_parser_test;
lst_parser_test = NULL;
ex_putstr("test putstr\n");
// char *str_parser = strdup("Un message simple,Bravo !,Dommage,|1er element|,2;Un autre message,Excellent,Raté,|un# dos# tres|,1");
lst_parser_test = ex_parser("/home/s/Bureau/CoursTam/j_7/partt.txt");
// ex_tester(lst_parser_test);
ex_list_del_all(&lst_parser_test, del_all_pars2);

char *str_get_file;
ex_putstr("test putstr\n");

str_get_file = ex_get_file("/home/s/Bureau/ffmpeg_5.1.1.orig/ffmpeg-5.1.1/libavcodec/dvbtxt.h");
 printf("str : \n[%s]   \n[%s] \n", str_get_file,"ght|,9;");
// lst_parser_test = ex_parser(str_get_file);
printf("size parser: %lld_____size get_file%lld",ex_strlen("Un message simple,Bravo !,Dommage,|1er element#2eme element# 3eme element|,2;Un autre message,Excellent,Raté,|un# dos# tres|,1; 1,2,3,|4#5#6#7#8|,9;one,two,tree,|four#five#six#seven#eight|,9;"), ex_strlen(str_get_file));
free(str_get_file);
ex_putstr("test putstr\n");

long test = 0;
    printf("%ld\n", test);
    printf("%ld\n", (test |= (1 << 4)));
    test = 0;
    printf("%ld\n", test);
    printf("%ld\n", (test |= (1 << 1)));
    printf("%ld\n", (test |= (1 << 0)));
    printf("%u\n", ~0U);


    affiche_bin((16<<0));
    affiche_bin(4294967295);
    affiche_bin(429496729);
    affiche_bin(4294967);
    affiche_bin(429496);
    affiche_bin(42949);
    affiche_bin(4294);

long opt = 0;
char *flag_test = "-abb";
char *flag_test_opt = "ABCDEFGabcdefghijklmnopqrstuvwxyz";
int typ = 2;

printf(" retour de check_opt :%d___\n", check_opts(flag_test, flag_test_opt, &opt, typ));
printf(" long opt : %ld\n", opt);
affiche_bin(opt);

ex_print_dir_rec("/");

//  struct stat sb;
//     if (ac != 2) {
//         fprintf(stderr, "Usage: %s <pathname>\n", av[0]);
//         exit(EXIT_FAILURE);
//     }

//     if (stat(av[1], &sb) == -1) {
//         perror("stat");
//         exit(EXIT_SUCCESS);
//     }

//     printf("Type de fichier :                ");

//     switch (sb.st_mode & S_IFMT) {
//     case S_IFBLK:  printf("périphérique de bloc\n");      break;
//     case S_IFCHR:  printf("périphérique de caractère\n"); break;
//     case S_IFDIR:  printf("répertoire\n");                break;
//     case S_IFIFO:  printf("FIFO/tube\n");                 break;
//     case S_IFLNK:  printf("lien symbolique\n");           break;
//     case S_IFREG:  printf("fichier ordinaire\n");         break;
//     case S_IFSOCK: printf("socket\n");                    break;
//     default:       printf("inconnu ?\n");                 break;
//     }
//     // struct passwd ps;
//     printf("Numéro d'inœud :                   %ld\n", (long) sb.st_ino);

//     printf("Mode :                             %lo (octal)\n",
//             (unsigned long) sb.st_mode);

//     printf("Nombre de liens :                  %ld\n", (long) sb.st_nlink);
//     printf("Propriétaires :                    UID=%ld   GID=%s\n",
//             (long) sb.st_uid,(getpwuid( sb.st_gid))->pw_name);

//     printf("Taille de bloc d’E/S :             %ld octets\n",
//             (long) sb.st_blksize);
//     printf("Taille du fichier :                %lld octets\n",
//             (long long) sb.st_size);
//     printf("Blocs alloués :                    %lld\n",
//             (long long) sb.st_blocks);

//     printf("Dernier changement d’état :        %s", ctime(&sb.st_ctime));
//     printf("Dernier accès au fichier :         %s", ctime(&sb.st_atime));
//     printf("Dernière modification du fichier:  %s", ctime(&sb.st_mtime));

//     exit(EXIT_SUCCESS);
 
    return 0;
}