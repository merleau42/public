/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_format_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dae-lee <dae-lee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 21:48:18 by dae-lee           #+#    #+#             */
/*   Updated: 2024/03/05 21:55:11 by dae-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_normal(char *normal_str)
{
	ft_putstr_fd(normal_str, 1);
	return (ft_strlen(normal_str));
}

int	print_c(int format_agr)
{
	ft_putchar_fd(format_agr, 1);
	return (1);
}

int	print_s(char *format_agr)
{
	if (format_agr == NULL)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	ft_putstr_fd(format_agr, 1);
	return (ft_strlen(format_agr));
}

int	print_p(void *format_agr)
{
	if (format_agr == NULL)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	ft_putstr_fd("0x", 1);
	putnbr_base_ull((unsigned long long)format_agr, "0123456789abcdef");
	return (2 + get_u_longlong2base_str_len(
			(unsigned long long)format_agr, 16));
}

int	print_d(int format_agr)
{
	ft_putnbr_fd(format_agr, 1);
	return (get_int2str_len(format_agr));
}
