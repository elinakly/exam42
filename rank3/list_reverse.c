void ft_list_reverse(t_list **begin_list)
{
    t_list *new_start;
    t_list *tmp;

    new_start = NULL;
    while (*begin_list)
    {
        tmp = (*begin_list)->next;
        (*begin_list)->next = new_start;
        new_start = *begin_list;
        *begin_list = tmp;
    }
    *begin_list = new_start;
}