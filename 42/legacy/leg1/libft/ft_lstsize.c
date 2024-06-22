
#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*node;
	int		ret;

	ret = 0;
	node = lst;
	while (node != NULL)
	{
		++ret;
		node = node -> next;
	}
	return (ret);
}
