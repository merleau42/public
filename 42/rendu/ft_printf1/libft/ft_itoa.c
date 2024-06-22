
#include "libft.h"

static int	ft_get_is_negative(int n)
{
	if (n < 0)
		return (1);
	return (0);
}

static int	ft_get_size_num(int n)
{
	int	ret;

	ret = 0;
	if (n == 0)
		ret++;
	else
	{
		while (n != 0)
		{
			n = n / 10;
			ret++;
		}
	}
	return (ret);
}

char	*ft_itoa(int n)
{
	char	*ret;
	int		size;
	int		divided;
	int		is_negative;

	is_negative = ft_get_is_negative(n);
	size = ft_get_size_num(n);
	if (is_negative)
		size += 1;
	ret = (char *)malloc ((size + 1) * sizeof(char));
	if (ret == NULL)
		return (NULL);
	ret[size] = '\0';
	while (size-- > 0)
	{
		divided = n % 10;
		if (divided < 0)
			divided *= (-1);
		ret[size] = divided + '0';
		n = n / 10;
	}
	if (is_negative)
		ret[0] = '-';
	return (ret);
}
