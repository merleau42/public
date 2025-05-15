/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keunkim <keunkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 04:50:59 by keunkim           #+#    #+#             */
/*   Updated: 2023/08/11 04:55:31 by keunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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

void	ft_putnbr_base(int nbr, char *base)
{
	char		conv[33];
	char		start;
	int			i;
	int			nary;
	long long	n;

	n = (long long)nbr;
	nary = vaild_base(base);
	if (nary < 2)
		return ;
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	i = 33;
	start = i - 1;
	while (i--)
	{
		conv[i] = base[n % nary];
		n = n / nary;
		if (conv[i] != base[0])
			start = i;
	}
	write(1, conv + start, 33 - start);
}
