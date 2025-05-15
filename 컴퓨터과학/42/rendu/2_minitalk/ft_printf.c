/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keunykim <keunykim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 17:20:51 by keunykim          #+#    #+#             */
/*   Updated: 2024/07/06 04:13:27 by keunykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return ((char *) s + i);
		i++;
	}
	if (c == '\0')
		return ((char *) s + i);
	else
		return (NULL);
}

static size_t	ft_putchar(int nbr)
{
	return (write(1, &nbr, 1));
}

static size_t	ft_putnbr(size_t nbr, char *base, int type)
{
	char	conv[65];
	char	front;
	int		index;
	int		nary;
	int		negative;

	nary = ft_strchr(base, '\0') - base;
	if (type == 'd' || type == 'i' || type == 'u')
		nbr = (unsigned int) nbr;
	if ((type == 'd' || type == 'i') && nbr == 2147483648)
		return (write(1, "-2147483648", 11));
	negative = ((type == 'd' || type == 'i') && (nbr >= 2147483648));
	if (negative)
		nbr = 0xFFFFFFFF - nbr + 1;
	index = 65;
	front = index - 1;
	while (index--)
	{
		conv[index] = base[nbr % nary];
		nbr = nbr / nary;
		if (conv[index] != base[0])
			front = index;
	}
	return (write(1, "-", negative) + write(1, conv + front, 65 - front));
}

static void	switch_board(va_list paras, const char *s, int *len)
{
	void	*p;

	if (*(s + 1) == '%')
		*len += write(1, "%", 1);
	if (*(s + 1) == 'd' || *(s + 1) == 'i')
		*len += ft_putnbr(va_arg(paras, int), "0123456789", 'i');
	if (*(s + 1) == 'u')
		*len += ft_putnbr(va_arg(paras, int), "0123456789", 'u');
	if (*(s + 1) == 'x')
		*len += ft_putnbr(va_arg(paras, int), "0123456789abcdef", 'u');
	if (*(s + 1) == 'X')
		*len += ft_putnbr(va_arg(paras, int), "0123456789ABCDEF", 'u');
	if (*(s + 1) == 'c')
		*len += ft_putchar(va_arg(paras, int));
	if (*(s + 1) == 's' || *(s + 1) == 'p')
		p = va_arg(paras, void *);
	if (*(s + 1) == 's' && p)
		*len += write(1, p, ft_strchr(p, '\0') - (char *) p);
	if (*(s + 1) == 'p' && p)
		*len += write(1, "0x", 2) + ft_putnbr((size_t)p, "0123456789abcdef", 0);
	if (*(s + 1) == 's' && !p)
		*len += write(1, "(null)", 6);
	if (*(s + 1) == 'p' && !p)
		*len += write(1, "(nil)", 5);
	*len = (ft_strchr("diuxXcsp%", *(s + 1)) != NULL) * (*len + 1) - 1;
}

int	ft_printf(const char *s, ...)
{
	va_list	paras;
	int		len;

	va_start(paras, s);
	len = 0;
	while (*s)
	{
		if (*s == '%')
		{
			switch_board(paras, s, &len);
			if (len == -1)
			{
				va_end(paras);
				return (-1);
			}
			s++;
		}
		else
			len += write(1, s, 1);
		s++;
	}
	va_end(paras);
	return (len);
}
