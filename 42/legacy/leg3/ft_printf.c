/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taegkang <taegkang@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 22:43:45 by dae-lee           #+#    #+#             */
/*   Updated: 2024/03/31 16:32:08 by taegkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	**get_format_strs(void)
{
	static char	*format_strs[] = {
		"%c",
		"%s",
		"%p",
		"%d",
		"%i",
		"%u",
		"%x",
		"%X",
		"%%",
		NULL
	};

	return (format_strs);
}

static int	get_format_type(char *str, char **format_strs)
{
	int	format_type;
	int	r;

	if (ft_strlen(str) != 2)
		return (F_NONE);
	format_type = 0;
	while (format_type != F_NONE)
	{
		r = ft_strncmp(str, format_strs[format_type], 2);
		if (r == 0)
			return (format_type);
		format_type++;
	}
	return (F_NONE);
}

static int	call_print_format(char *str, char **format_strs, va_list ap)
{
	int	format_type;

	format_type = get_format_type(str, format_strs);
	if (format_type == F_C)
		return (print_c(va_arg(ap, int)));
	else if (format_type == F_S)
		return (print_s(va_arg(ap, char *)));
	else if (format_type == F_P)
		return (print_p(va_arg(ap, void *)));
	else if (format_type == F_D)
		return (print_d(va_arg(ap, int)));
	else if (format_type == F_I)
		return (print_i(va_arg(ap, int)));
	else if (format_type == F_U)
		return (print_u(va_arg(ap, int)));
	else if (format_type == F_X)
		return (print_x(va_arg(ap, int)));
	else if (format_type == F_XX)
		return (print_xx(va_arg(ap, int)));
	else if (format_type == F_PERCENT)
		return (print_percent());
	else
		return (print_normal(str));
}

int	ft_printf(const char *format, ...)
{
	char	**format_strs;
	char	**strs;
	char	**tmp;
	int		print_str_len;
	va_list	ap;

	if (format == NULL)
		return (-1);
	format_strs = get_format_strs();
	strs = split_fstring(format, format_strs);
	if (strs == NULL)
		return (-1);
	tmp = strs;
	print_str_len = 0;
	va_start(ap, format);
	while (*strs != NULL)
		print_str_len += call_print_format(*strs++, format_strs, ap);
	va_end(ap);
	strs = tmp;
	while (*strs != NULL)
		free(*strs++);
	free(tmp);
	return (print_str_len);
}

int main()
{
	int a;
	char b[30] = "abcdefghijk";
	int c;

	//ft_printf(" X : %X1123\n c : %cab1234\n d : %d3334\n u : %uasdfa\n p : %p \n %% : %%\n", 2147483647, 'a', -2147483647, -1, 5555);
	a = ft_printf("abc  %s %p %x %X  adef%v", b, b, 15, 15);
	c = printf("abc  %s %p %x %X  adef%v", b, b, 15, 15);
	printf("%d %d\n", a, c);
	return 0;
}
