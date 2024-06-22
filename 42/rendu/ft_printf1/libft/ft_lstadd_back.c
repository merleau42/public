
#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*obj;

	if (lst == NULL || new == NULL)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		obj = *lst;
		while (obj -> next != NULL)
			obj = obj -> next;
		obj -> next = new;
	}
}
