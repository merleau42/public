/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_format_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dae-lee <dae-lee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 21:48:12 by dae-lee           #+#    #+#             */
/*   Updated: 2024/03/05 21:55:17 by dae-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_i(int format_agr)
{
	ft_putnbr_fd(format_agr, 1);
	return (get_int2str_len(format_agr));
}

int	print_u(unsigned int format_agr)
{
	putnbr_ui(format_agr);
	return (get_u_int2str_len(format_agr));
}

int	print_x(unsigned int format_agr)
{
	putnbr_base_ull(format_agr, "0123456789abcdef");
	return (get_u_longlong2base_str_len(format_agr, 16));
}

int	print_xx(unsigned int format_agr)
{
	putnbr_base_ull(format_agr, "0123456789ABCDEF");
	return (get_u_longlong2base_str_len(format_agr, 16));
}

int	print_percent(void)
{
	ft_putchar_fd('%', 1);
	return (1);
}
