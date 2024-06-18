
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t		multiply;
	void		*ret;

	multiply = nmemb * size;
	if (nmemb > 0 && size != (multiply / nmemb))
	{
		return (NULL);
	}
	ret = malloc(nmemb * size);
	if (ret == NULL)
	{
		return (NULL);
	}
	ft_memset(ret, 0, nmemb * size);
	return (ret);
}
