/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taegkang <taegkang@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 08:39:30 by taegkang          #+#    #+#             */
/*   Updated: 2024/04/29 18:19:00 by taegkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# define SMALL "0123456789abcdef"
# define BIG "0123456789ABCDEF"

size_t			ft_strlen(const char *s);
char			*ft_itoa(int n);
char			*ft_utoa(unsigned int n);
unsigned int	ft_putnbr_base(unsigned int nbr, const char *base);
size_t			ft_putnbr_base_size_t(size_t nbr, const char *base);
int				ft_printf(const char *s, ...);

#endif