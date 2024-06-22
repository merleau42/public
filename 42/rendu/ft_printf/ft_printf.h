/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keunykim <keunykim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 17:20:57 by keunykim          #+#    #+#             */
/*   Updated: 2024/06/22 18:00:01 by keunykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define HEXLOWER "0123456789abcdef"
# define HEXUPPER "0123456789ABCDEF"
# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *s, ...);
void	ft_process(va_list paras, const char *s, int *len);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
size_t	ft_putchar(int nbr);
size_t	ft_putnbr_base(int nbr, char *base);
size_t	ft_putnbr_base_uint(unsigned int nbr, char *base);
size_t	ft_putnbr_base_szt(size_t nbr, char *base);

#endif