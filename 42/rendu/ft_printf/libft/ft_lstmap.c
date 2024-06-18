
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*obj;
	t_list	*ret;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	ret = NULL;
	while (lst != NULL)
	{
		obj = ft_lstnew(f(lst -> content));
		if (obj == NULL)
		{
			ft_lstclear(&ret, del);
			return (0);
		}
		else
		{
			ft_lstadd_back(&ret, obj);
			lst = lst -> next;
		}
	}
	return (ret);
}
