
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	big_index;
	size_t	little_index;
	char	*ret;

	big_index = 0;
	ret = NULL;
	if (*little == '\0' || ft_strlen(little) == 0)
		return ((char *)big);
	while (big_index < len && big[big_index])
	{
		little_index = 0;
		while (big[big_index + little_index] == little[little_index] && \
				little_index < len && big_index + little_index < len)
		{
			if (little[little_index + 1] == '\0')
				return ((char *)big + big_index);
			little_index++;
		}
		big_index++;
	}
	return (ret);
}
