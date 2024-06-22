
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	size_t	index;
	size_t	s1_size;
	size_t	s2_size;

	index = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s1_size = ft_strlen(s1);
	s2_size = ft_strlen(s2);
	ret = malloc(s1_size + s2_size + 1);
	if (ret == NULL)
		return (NULL);
	while (index < s1_size + s2_size)
	{
		if (index < s1_size)
			ret[index] = s1[index];
		else
			ret[index] = s2[index - s1_size];
		index++;
	}
	ret[index] = '\0';
	return (ret);
}
