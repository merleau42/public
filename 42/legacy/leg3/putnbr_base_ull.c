/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr_base_ull.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dae-lee <dae-lee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 03:50:13 by dae-lee           #+#    #+#             */
/*   Updated: 2024/03/05 19:44:43 by dae-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	is_valied_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		while (j < i)
		{
			if (base[j] == base[i])
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	if (i == 0 || i == 1)
		return (0);
	return (1);
}

static void	print_nbr_by_base_ull(unsigned long long nbr,
	unsigned long long base_size, char *base)
{
	if (nbr < base_size)
	{
		write(1, base + nbr, 1);
	}
	else
	{
		print_nbr_by_base_ull((nbr / base_size), base_size, base);
		print_nbr_by_base_ull((nbr % base_size), base_size, base);
	}
}

// use base notation to putnbr (unsigned long long Number)
void	putnbr_base_ull(unsigned long long nbr, char *base)
{
	int	base_size;

	if (!is_valied_base(base))
		return ;
	base_size = 0;
	while (base[base_size])
		base_size++;
	print_nbr_by_base_ull(nbr, base_size, base);
}

// Find the output str length that matches the base number.
size_t	get_u_longlong2base_str_len(unsigned long long nbr,
	unsigned long long base_size)
{
	size_t	str_length;

	str_length = 1;
	while (nbr >= base_size)
	{
		nbr = nbr / base_size;
		str_length++;
	}
	return (str_length);
}
