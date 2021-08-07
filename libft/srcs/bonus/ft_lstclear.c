#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*curr;
	t_list	*tmp;

	curr = (*lst);
	while (curr)
	{
		del(curr->content);
		tmp = curr->next;
		free(curr);
		curr = tmp;
	}
	(*lst) = NULL;
}