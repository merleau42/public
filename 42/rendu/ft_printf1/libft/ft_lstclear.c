
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*obj;

	if (lst == NULL || del == NULL)
		return ;
	while (*lst != NULL)
	{
		obj = *lst;
		del(obj -> content);
		*lst = obj -> next;
		free(obj);
	}
}
