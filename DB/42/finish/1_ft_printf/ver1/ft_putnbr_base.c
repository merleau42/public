/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keunykim <keunykim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 17:20:54 by keunykim          #+#    #+#             */
/*   Updated: 2024/06/22 17:35:53 by keunykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putnbr_base(int nbr, char *base)
{
	char	conv[65];
	char	front;
	int		index;
	int		nary;
	int		negative;

	nary = ft_strlen(base);
	if (nbr == -2147483648)
		return (write(1, "-2147483648", 11));
	negative = (nbr < 0);
	if (negative)
	{
		write(1, "-", 1);
		nbr = -nbr;
	}
	index = 65;
	front = index - 1;
	while (index--)
	{
		conv[index] = base[nbr % nary];
		nbr = nbr / nary;
		if (conv[index] != base[0])
			front = index;
	}
	return (write(1, conv + front, 65 - front) + negative);
}

size_t	ft_putnbr_base_uint(unsigned int nbr, char *base)
{
	char	conv[65];
	char	front;
	int		index;
	int		nary;

	nary = ft_strlen(base);
	index = 65;
	front = index - 1;
	while (index--)
	{
		conv[index] = base[nbr % nary];
		nbr = nbr / nary;
		if (conv[index] != base[0])
			front = index;
	}
	return (write(1, conv + front, 65 - front));
}

size_t	ft_putnbr_base_szt(size_t nbr, char *base)
{
	char	conv[65];
	char	front;
	int		index;
	int		nary;

	nary = ft_strlen(base);
	index = 65;
	front = index - 1;
	while (index--)
	{
		conv[index] = base[nbr % nary];
		nbr = nbr / nary;
		if (conv[index] != base[0])
			front = index;
	}
	return (write(1, conv + front, 65 - front));
}
