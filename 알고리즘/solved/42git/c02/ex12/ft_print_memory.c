/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keunkim <keunkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 12:57:03 by keunkim           #+#    #+#             */
/*   Updated: 2023/08/06 14:26:42 by keunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_put_address(unsigned long long bit64)
{
	char	*dict;
	char	conv[16];
	int		i;

	dict = "0123456789abcdef";
	i = 16;
	while (i--)
	{
		conv[i] = dict[bit64 % 16];
		bit64 = bit64 / 16;
	}
	write(1, conv, 16);
}

void	ft_put_contents_in_hex(unsigned char *str, int size)
{
	char	*dict;
	char	digit[2];
	int		i;

	dict = "0123456789abcdef";
	i = 1;
	while (i <= size)
	{
		digit[0] = dict[*str / 16];
		digit[1] = dict[*str % 16];
		write(1, digit, 2);
		if (i % 2 == 0)
			write(1, " ", 1);
		str++;
		i++;
	}
	while (i <= 16)
	{
		write(1, "  ", 2);
		if (i % 2 == 0)
			write(1, " ", 1);
		i++;
	}
}

void	ft_write(char *str, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (32 <= str[i] && str[i] <= 126)
			write(1, &str[i], 1);
		else
			write(1, ".", 1);
		i++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	void	*rewind;
	int		line;

	rewind = addr;
	line = size / 16;
	while (line--)
	{
		ft_put_address((unsigned long long)addr);
		write(1, ": ", 2);
		ft_put_contents_in_hex((unsigned char *)addr, 16);
		ft_write(addr, 16);
		write(1, "\n", 1);
		addr += 16;
	}
	if (size % 16 > 0)
	{
		ft_put_address((unsigned long long)addr);
		write(1, ": ", 2);
		ft_put_contents_in_hex((unsigned char *)addr, size % 16);
		ft_write(addr, size % 16);
		write(1, "\n", 1);
	}
	return (rewind);
}
