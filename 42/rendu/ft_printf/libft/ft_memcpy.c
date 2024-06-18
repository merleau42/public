
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	index;

	index = 0;
	if (dest == NULL && src == NULL)
		return (0);
	while (index < n)
	{
		((char *)dest)[index] = ((char *)src)[index];
		index++;
	}
	return (dest);
}
