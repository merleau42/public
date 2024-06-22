
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*ret;
	unsigned int	index;
	size_t			size;

	if (s == NULL || f == NULL)
		return (NULL);
	size = ft_strlen(s);
	ret = malloc(size * sizeof(char) + 1);
	if (ret == NULL)
		return (NULL);
	index = 0;
	while (index < size)
	{
		ret[index] = f(index, s[index]);
		index++;
	}
	ret[index] = '\0';
	return (ret);
}
