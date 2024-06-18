
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int		ret;
	size_t	index;

	index = 0;
	ret = 0;
	if (n == 0)
		return (0);
	while (index + 1 < n && s1[index] != '\0')
	{
		ret = (unsigned char)s1[index] - (unsigned char)s2[index];
		if (ret != 0)
		{
			break ;
		}
		index++;
	}
	ret = (unsigned char)s1[index] - (unsigned char)s2[index];
	return (ret);
}
