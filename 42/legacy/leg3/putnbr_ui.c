/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr_ui.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dae-lee <dae-lee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 20:35:44 by dae-lee           #+#    #+#             */
/*   Updated: 2024/03/05 19:41:45 by dae-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// output putnbr (unsigned int value)
void	putnbr_ui(unsigned int n)
{
	char	c;

	if (n > 9)
	{
		putnbr_ui(n / 10);
		putnbr_ui(n % 10);
	}
	else
	{
		c = n + '0';
		write(1, &c, 1);
	}
}

// Find the length of the decimal output str of the int value.
size_t	get_int2str_len(int int_value)
{
	long	un;
	int		str_length;

	un = int_value;
	str_length = 0;
	if (un < 0)
	{
		un = -un;
		str_length++;
	}
	str_length++;
	while (un >= 10)
	{
		un /= 10;
		str_length++;
	}
	return (str_length);
}

// Find the decimal output str length of the unsigned int value.
size_t	get_u_int2str_len(unsigned int u_int_value)
{
	size_t		str_length;

	str_length = 1;
	while (u_int_value >= 10)
	{
		u_int_value /= 10;
		str_length++;
	}
	return (str_length);
}
