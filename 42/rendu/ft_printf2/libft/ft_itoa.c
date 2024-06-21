
#include "./libft.h"

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

static char	*ft_insert_num(char *str, long long n_cpy, int sign, int digit)
{
	long long	num;	
	int			idx;

	idx = digit - 1 + sign;
	while (idx >= 0 + sign)
	{
		num = n_cpy % 10;
		n_cpy /= 10;
		str[idx] = num + '0';
		idx--;
	}
	if (sign)
		str[0] = '-';
	str[digit + sign] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	long long	n_cpy;
	int			digit;
	int			sign;
	char		*str;

	sign = 0;
	n_cpy = n;
	if (n_cpy < 0)
	{
		sign = 1;
		n_cpy = -n_cpy;
	}
	digit = ft_get_digit(n_cpy);
	str = (char *)malloc(sizeof(char) * (digit + 1 + sign));
	if (!str)
		return (NULL);
	ft_insert_num(str, n_cpy, sign, digit);
	return (str);
}
