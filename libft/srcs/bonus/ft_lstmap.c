#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *tmp;
	t_list *new;
	t_list *newelem;

	new = 0;
	tmp = lst;
	while(tmp)
	{
		if (!(newelem = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&new, del);
			return (new);
		}
		ft_lstadd_back(&new, newelem);
		tmp = tmp->next;
	}
	return (new);
}