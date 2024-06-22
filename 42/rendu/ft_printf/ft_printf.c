#include "ft_printf.h"

size_t	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

size_t	ft_process(va_list paras, const char *s)
{
	char	*byte4;
	char	*byte8;

	if (*(s + 1) == 'c')
		return write(1, &va_arg(paras, int), 1);
	if (*(s + 1) == '%')
		return write(1, "%", 1);
	if (*(s + 1) == 's')
	{
		byte8 = va_arg(paras, char *);
		if (byte8)
			return write(1, str, ft_strlen(str));
		return write(1, "(null)", 6);
	}
	if (*(s + 1) == 'd' || *(s + 1) == 'i')
	{
		byte4 = itoa(va_arg(paras, int));
		if (!byte4)
			return -1;
		len += write(1, byte4, ft_strlen(byte4));
		free(byte4);
	}
	if (*(s + 1) == 'u')
	{
		byte4 = utoa(va_arg(paras, unsigned int));
		if (!byte4)
			return -1;
		len += write(1, byte4, ft_strlen(byte4));
		free(byte4);
	}
	if (*(s + 1) == 'p')
	{
		byte8 = va_arg(paras, void *);
		if (!byte8)
			return write(1, "(nil)", 5);
		return write(1, "0x", 2) + ft_putnbr_base_size_t((size_t)byte8, "0123456789abcdef");
	}
	if (*(s + 1) == 'x')
		return ft_putnbr_base(va_arg(paras, int), "0123456789abcdef");
	if (*(s + 1) == 'X')
		return ft_putnbr_base(va_arg(paras, int), "0123456789ABCDEF");
	return -1;
}

int	ft_printf(const char *s, ...)
{
	va_list	paras;
	size_t	len;

	va_start(paras, s);
	len = 0;
	while (*s)
	{
		if (*s == '%')
		{
			len += ft_process(paras, s);
			s++;
		}
		else
			len += write(1, s, 1);
		s++;
	}
	va_end(paras);
	return (len);
}
