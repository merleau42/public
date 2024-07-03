#include "minitalk.h"

int	ft_atoi(const char *nptr)
{
	int	res;
	int	sign;
	int	i;

	res = 0;
	sign = 1;
	i = 0;
	while ((9 <= nptr[i] && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
		sign = sign * (44 - nptr[i++]);
	if (nptr[i] == '-' || nptr[i] == '+')
		return (0);
	while ('0' <= nptr[i] && nptr[i] <= '9')
		res = 10 * res + (nptr[i++] - '0');
	return (res * sign);
}

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*bytes;
	size_t			i;

	bytes = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		bytes[i] = (unsigned char) c;
		i++;
	}
	return (s);
}

int	vaild_base2(char *base)
{
	int				i;
	int				exist[256];
	unsigned char	bf;

	i = 0;
	while (i < 256)
		exist[i++] = 0;
	i = 0;
	while (base[i] != '\0')
	{
		bf = (unsigned char) base[i];
		exist[(int)bf]++;
		i++;
		if (bf == ' ' || bf == '-' || bf == '+' || exist[(int)bf] >= 2)
			return (0);
		if (9 <= bf && bf <= 13)
			return (0);
	}
	return (i);
}

int	custom_number(char ch, char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (ch == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	res;
	int	sign;
	int	nary;
	int	i;

	res = 0;
	sign = 1;
	i = 0;
	nary = vaild_base2(base);
	if (nary < 2)
		return (0);
	while ((9 <= str[i] && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] == '-' || str[i] == '+')
		sign = sign * (44 - str[i++]);
	while (custom_number(str[i], base) != -1)
		res = nary * res + custom_number(str[i++], base);
	return (res * sign);
}
