void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list *tmp;
	t_list *current;
	t_list *prev;

	while (*begin_list && !cmp((*begin_list)->data, data_ref))
	{
		tmp = *begin_list;
		*begin_list = tmp->next;
		free(tmp);
	}
	prev = *begin_list;
	if (!prev)
		return;
	current = prev->next;
	while (current)
	{
		if (!cmp(current->data, data_ref))
		{
			tmp = current;
			prev->next = current->next;
			current = current->next;
			free(tmp);
		}
		else
		{
			prev = current;
			current = current->next;
		}
	}
}
