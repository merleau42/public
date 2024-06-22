/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taegkang <taegkang@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 12:05:12 by dae-lee           #+#    #+#             */
/*   Updated: 2024/03/31 16:30:01 by taegkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

// ft_ functions
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t sz);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
// added functions
char	**split_fstring(char const *str, char **format_sep);
void	putnbr_ui(unsigned int n);
size_t	get_int2str_len(int int_value);
size_t	get_u_int2str_len(unsigned int u_int_value);
void	putnbr_base_ull(unsigned long long nbr, char *base);
size_t	get_u_longlong2base_str_len(unsigned long long nbr,
			unsigned long long base_size);
// ft_printf functions
int		ft_printf(const char *format, ...);
int		print_normal(char *normal_str);
int		print_c(int format_agr);
int		print_s(char *format_agr);
int		print_p(void *format_agr);
int		print_d(int format_agr);
int		print_i(int format_agr);
int		print_u(unsigned int format_agr);
int		print_x(unsigned int format_agr);
int		print_xx(unsigned int format_agr);
int		print_percent(void);

enum		e_format_type {
	F_C,
	F_S,
	F_P,
	F_D,
	F_I,
	F_U,
	F_X,
	F_XX,
	F_PERCENT,
	F_NONE,
};

#endif
