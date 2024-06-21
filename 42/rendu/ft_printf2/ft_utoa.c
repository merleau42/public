
#include "ft_printf.h"

static int	ft_get_digit(long long n)
{
	int	digit;

	if (n == 0)
		return (1);
	digit = 0;
	while (n > 0)
	{
		n /= 10;
		digit++;
	}
	return (digit);
}

static char	*ft_insert_num(char *str, long long n_cpy, int digit)
{
	long long	num;	
	int			idx;

	idx = digit - 1;
	while (idx >= 0)
	{
		num = n_cpy % 10;
		n_cpy /= 10;
		str[idx] = num + '0';
		idx--;
	}
	str[digit] = '\0';
	return (str);
}

char	*ft_utoa(unsigned int n)
{
	unsigned int	n_cpy;
	int				digit;
	char			*str;

	n_cpy = n;
	digit = ft_get_digit(n_cpy);
	str = (char *)malloc(sizeof(char) * (digit + 1));
	if (!str)
		return (NULL);
	ft_insert_num(str, n_cpy, digit);
	return (str);
}
