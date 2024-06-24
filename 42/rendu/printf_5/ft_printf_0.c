/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keunykim <keunykim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 17:20:51 by keunykim          #+#    #+#             */
/*   Updated: 2024/06/24 19:50:15 by keunykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strchr(const char *s, int c)
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

size_t	ft_putchar(int nbr)
{
	return (write(1, &nbr, 1));
}

void	ft_process(va_list paras, const char *s, int *len)
{
	void	*ptr;

	if (*(s + 1) == '%')
		*len += write(1, "%", 1);
	if (*(s + 1) == 'd' || *(s + 1) == 'i')
		*len += ft_putnbr_base(va_arg(paras, int), "0123456789");
	if (*(s + 1) == 'u')
		*len += ft_putnbr_base_uint(va_arg(paras, int), "0123456789");
	if (*(s + 1) == 'x')
		*len += ft_putnbr_base_uint(va_arg(paras, int), HEXLOWER);
	if (*(s + 1) == 'X')
		*len += ft_putnbr_base_uint(va_arg(paras, int), HEXUPPER);
	if (*(s + 1) == 'c')
		*len += ft_putchar(va_arg(paras, int));
	if (*(s + 1) == 's' || *(s + 1) == 'p')
		ptr = va_arg(paras, void *);
	if (*(s + 1) == 's' && ptr)
		*len += write(1, ptr, ft_strchr(ptr, '\0') - (char *) ptr);
	if (*(s + 1) == 'p' && ptr)
		*len += write(1, "0x", 2) + ft_putnbr_base_szt((size_t)ptr, HEXLOWER);
	if (*(s + 1) == 's' && !ptr)
		*len += write(1, "(null)", 6);
	if (*(s + 1) == 'p' && !ptr)
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
			ft_process(paras, s, &len);
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
