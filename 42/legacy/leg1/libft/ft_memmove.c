
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	ssize_t	index;

	if (dest == NULL && src == NULL)
		return (0);
	if (dest < src)
	{
		index = 0;
		while (index < (ssize_t)n)
		{
			((char *)dest)[index] = ((char *)src)[index];
			index++;
		}
	}
	else
	{
		index = (ssize_t)n;
		while (index-- > 0)
		{
			((char *)dest)[index] = ((char *)src)[index];
		}
	}
	return (dest);
}
