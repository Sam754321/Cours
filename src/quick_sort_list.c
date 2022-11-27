#include "libtam.h"

struct t_list *pivot_point(struct t_list *start, struct t_list *end)
{
    struct t_list *pivot;
    struct t_list *iter_lst_pivot;
    struct t_content tmp_content;
    pivot = start;
    iter_lst_pivot = start;
    
    while(iter_lst_pivot =! NULL && iter_lst_pivot != end)
    {
        if(iter_lst_pivot->content-> (><=) end->content->)
        {
            pivot = start;
            tmp_content = start->content;
            start->content = iter_lst_pivot->content;
            iter_lst_pivot->content = tmp_content;
            start = start->next;
        }
        iter_lst_pivot = iter_lst_pivot->next;
    }
    tmp_content = start->content;
    start->content = end->content;
    end->content = tmp_content;
    return pivot;
}

void quick_sort(t_list *head, t_list *last)
{
    struct t_list *pivot;

    if(head == last)
        return;
    pivot = pivot_point(head, last);
    if(pivot != NULL && pivot->next != NULL)
        quick_sort(pivot->next, last);
    if(pivot != NULL && head != pivot)
        quick_sort(head, pivot);
}
