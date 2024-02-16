/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keunykim <keunykim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 09:17:29 by keunykim          #+#    #+#             */
/*   Updated: 2023/12/20 18:13:51 by keunykim         ###   ########.fr       */
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
