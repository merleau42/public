
#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	dest_index;
	size_t	src_index;

	if (dest == NULL)
		dest_len = 0;
	else
		dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	dest_index = dest_len;
	src_index = 0;
	if (size <= dest_len)
		return (src_len + size);
	while (src[src_index] && dest_index < size - 1)
	{
		dest[dest_index++] = src[src_index++];
	}
	dest[dest_index] = '\0';
	return (dest_len + src_len);
}
