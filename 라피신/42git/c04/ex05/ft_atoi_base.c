/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keunkim <keunkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 04:47:23 by keunkim           #+#    #+#             */
/*   Updated: 2023/08/11 05:04:49 by keunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	vaild_base(char *base)
{
	int				i;
	int				exist[256];
	unsigned char	bf;

	i = 0;
	while (i < 256)
		exist[i++] = 0;
	i = 0;
	while (base[i] != 0)
	{
		bf = (unsigned char) base[i];
		exist[(int)bf]++;
		i++;
		if (bf == '-' || bf == '+' || bf == ' ' || exist[(int)bf] >= 2)
			return (0);
		if (bf == '\t' || bf == '\n' || bf == '\v' || bf == '\f' || bf == '\r')
			return (0);
	}
	return (i);
}

int	is_custom_number(char ch, char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0' && ch != base[i])
		i++;
	return (i);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	res;
	int	sign;
	int	nary;

	i = -1;
	res = -1;
	sign = 1;
	nary = vaild_base(base);
	if (nary < 2)
		return (0);
	while (str[++i] != '\0')
	{
		if (is_custom_number(str[i], base) < ft_strlen(base))
			res = nary * res * (res != -1) + is_custom_number(str[i], base);
		else if (res == -1 && str[i] == '-')
			sign = -sign;
		else if (res != -1)
			break ;
		if (str[i] == '+' || str[i] == '-')
			if (str[i + 1] != '+' && str[i + 1] != '-')
				if (!(is_custom_number(str[i + 1], base) < ft_strlen(base)))
					return (0);
	}
	return (res * sign * (res != -1));
}
