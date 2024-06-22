
#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	index;
	size_t			size;

	if (s == NULL || f == NULL)
		return ;
	size = ft_strlen(s);
	index = 0;
	while (index < size)
	{
		f(index, &s[index]);
		index++;
	}
}
