/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keunkim <keunkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 04:49:27 by keunkim           #+#    #+#             */
/*   Updated: 2023/08/11 04:49:48 by keunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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
			conv[i] = nb % 10 + '0';
			nb = nb / 10;
			if (conv[i] != '0')
				start = i;
		}
		write(1, conv + start, 10 - start);
	}
}
