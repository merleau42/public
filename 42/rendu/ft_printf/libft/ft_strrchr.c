
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		index;
	size_t	size;
	char	*ret;

	ret = NULL;
	size = ft_strlen(s);
	index = (int)size;
	while (index >= 0)
	{
		if (s[index] == ((char)c))
		{
			ret = &((char *)s)[index];
			break ;
		}
		index--;
	}
	return (ret);
}
