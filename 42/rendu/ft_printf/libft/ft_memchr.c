
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*copied;
	size_t	index;
	void	*ret;

	copied = (char *)s;
	index = 0;
	ret = NULL;
	while (index < n)
	{
		if (copied[index] == (char)c)
		{
			ret = (void *)(&copied[index]);
			break ;
		}
		index++;
	}
	return (ret);
}
