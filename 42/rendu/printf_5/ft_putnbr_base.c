/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keunykim <keunykim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 17:20:54 by keunykim          #+#    #+#             */
/*   Updated: 2024/06/24 23:11:34 by keunykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putnbr_base(int nbr, char *base)
{
	char		conv[65];
	char		front;
	int			index;
	const int	nary = ft_strchr(base, '\0') - base;
	const int	nagative = (nbr < 0);

	if (nbr == -2147483648)
		return (write(1, "-2147483648", 11));
	nbr = (1 - 2 * nagative) * nbr;
	index = 65;
	front = index - 1;
	while (index--)
	{
		conv[index] = base[nbr % nary];
		nbr = nbr / nary;
		if (conv[index] != base[0])
			front = index;
	}
	return (write(1, "-", nagative) + write(1, conv + front, 65 - front));
}

size_t	putnbr_base(size_t nbr, char *base, char type)
{
	char		conv[65];
	char		front;
	int			index;
	const int	nary = ft_strchr(base, '\0') - base;
	int			nagative;

	if (type == 'u' || type == 'i')
		nbr = nbr % (4294967296);
	if (type == 'i' && (int)nbr == -2147483648)
		return (write(1, "-2147483648", 11));
	if (type == 'i' && (int)nbr < 0)
	{
		nagative = 1;
		nbr = nbr ...;
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
	return (write(1, "-", nagative) + write(1, conv + front, 65 - front));
	// return (write(1, conv + front, 65 - front));
}