
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int		ret;
	size_t	index;

	index = 0;
	ret = 0;
	while (index < n)
	{
		ret = (((unsigned char *)s1)[index] - ((unsigned char *)s2)[index]);
		if (ret != 0)
		{
			break ;
		}
		index++;
	}
	return (ret);
}
