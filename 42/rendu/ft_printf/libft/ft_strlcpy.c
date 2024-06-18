
#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	result;
	size_t	index;

	result = 0;
	index = 0;
	while (src[result])
		result++;
	if (size == 0)
		return (result);
	while (index + 1 < size && src[index] != '\0')
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = '\0';
	return (result);
}
