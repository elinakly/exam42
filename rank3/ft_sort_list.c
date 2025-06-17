t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
    t_list *current;
    int swapped;
    int tmp;

    swapped = 1;
    while (swapped)
    {
        swapped = 0;
        current = lst;
        while (current->next)
        {
            if (!cmp(current->data, current->next->data))
            {
                tmp = current->data;
                current->data = current->next->data;
                current->next->data = tmp;
                swapped = 1;
            }
            current=current->next;
        }
    }
    return(lst);
}