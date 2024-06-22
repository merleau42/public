
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*ret;
	unsigned int	index;
	size_t			count;

	if (s == NULL)
		return (NULL);
	if (ft_strlen(s) < start)
	{
		ret = (char *)ft_calloc(sizeof(char), len);
		return (ret);
	}
	index = 0;
	ret = (char *)malloc(((len + 1) * sizeof(char)));
	if (ret == NULL)
		return (NULL);
	count = (size_t)start;
	if (start < ft_strlen(s))
	{
		while (count < (size_t)(start + len))
			ret[index++] = s[count++];
	}
	ret[index] = '\0';
	return (ret);
}
