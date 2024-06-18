
#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t		index;
	size_t		size;
	char		*ret;

	index = 0;
	size = ft_strlen(s) * sizeof(char);
	ret = malloc(size + 1);
	if (ret == NULL)
		return (NULL);
	while (index < size)
	{
		((char *)ret)[index] = s[index];
		index++;
	}
	((char *)ret)[index] = '\0';
	return (ret);
}
