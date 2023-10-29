/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keunkim <keunkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 11:04:00 by keunkim           #+#    #+#             */
/*   Updated: 2023/08/05 15:06:41 by keunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned long long	ft_pow(int n, int a)
{
	if (a)
		return (ft_pow(n, a - 1) * n);
	else
		return (1);
}

void	ft_putnbr(int nb)
{
	char	conv[10];
	char	start;
	int		i;

	if (nb == -2147483648)
		write(1, "-2147483648", 11);
	else
	{
		if (nb < 0)
		{
			write(1, "-", 1);
			nb = -nb;
		}
		i = 10;
		start = 9;
		while (i--)
		{
			conv[i] = nb % ft_pow(10, (10 - i)) / ft_pow(10, (9 - i)) + '0';
			if (conv[i] != '0')
				start = i;
		}
		write(1, conv + start, 10 - start);
	}
}
