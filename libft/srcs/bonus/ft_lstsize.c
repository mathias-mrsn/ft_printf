#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list *tmp;
	int	count;

	tmp = lst;
	count = 0;
	while(tmp)
	{
		count++;
		tmp = tmp->next;
	}
	return (count);
}