
#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*ret;

	if (lst == NULL)
		return (NULL);
	ret = lst;
	while (ret -> next != NULL)
		ret = ret -> next;
	return (ret);
}
