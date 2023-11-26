#include <stdio.h>
#include <stdlib.h>

int		ft_strlen(char *str);

char	*decimal_to_base(long int n, char *base);

int	get_index(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	ft_is_space(char c)
{
	return (c == ' ' || c == '\f'
		|| c == '\n' || c == '\r'
		|| c == '\t' || c == '\v');
}

int	is_invalid(char *base)
{	
	int	i;
	int	k;

	i = 0;
	if (base == NULL)
		return (1);
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-' || ft_is_space(base[i]))
			return (1);
		k = i + 1;
		while (base[k] != '\0')
		{
			if (base[i] == base[k])
				return (1);
			k++;
		}	
		i++;
	}
	return (i <= 1);
}

long int	base_to_decimal(char *nbr, char *base)
{
	int			i;
	int			base_size;
	int			is_negative;
	long int	res;

	i = 0;
	res = 0;
	is_negative = 0;
	base_size = ft_strlen(base);
	while (ft_is_space(nbr[i]))
		i++;
	while (nbr[i] == '-' || nbr[i] == '+')
	{
		if (nbr[i] == '-')
			is_negative = !is_negative;
		i++;
	}
	while (get_index(nbr[i], base) != -1 && nbr[i] != '\0')
	{
		res = res * base_size + get_index(nbr[i], base);
		i++;
	}
	if (is_negative)
		return (-res);
	return (res);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long int	n;
	char		*res;

	if (is_invalid(base_from) || is_invalid(base_to) || nbr == NULL)
		return (NULL);
	n = base_to_decimal(nbr, base_from);
	res = decimal_to_base(n, base_to);
	return (res);
}
