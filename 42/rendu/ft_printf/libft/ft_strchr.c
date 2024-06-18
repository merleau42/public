
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	index;
	size_t	size;
	char	*ret;

	ret = NULL;
	size = ft_strlen(s);
	index = 0;
	while (index <= size)
	{
		if (s[index] == ((char)c))
		{
			ret = &((char *)s)[index];
			break ;
		}
		index++;
	}
	return (ret);
}
