
#include "libft.h"

static int	ft_is_white_space(char character)
{
	if ((character >= 9 && character <= 13) || character == 32)
	{
		return (1);
	}
	return (0);
}

int	ft_atoi(const char *nptr)
{
	size_t	index;
	int		ret;
	int		is_negative;

	ret = 0;
	index = 0;
	is_negative = 1;
	while (ft_is_white_space(nptr[index]))
		index++;
	if (nptr[index] == '+' || nptr[index] == '-')
	{
		if (nptr[index] == '-')
			is_negative *= (-1);
		index++;
	}
	while (nptr[index] >= '0' && nptr[index] <= '9')
	{
		ret = ret * 10 + (nptr[index] - 48);
		index++;
	}
	ret *= is_negative;
	return (ret);
}
