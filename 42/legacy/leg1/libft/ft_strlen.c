
#include "libft.h"

size_t	ft_strlen(const char *s)
{
	const char	*copied;

	copied = s;
	while (*copied != '\0')
	{
		copied++;
	}
	return (copied - s);
}
