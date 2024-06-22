#include "ft_printf.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

size_t	ft_process(va_list paras, const char *s)
{
	char	*str;
	char	*ptr;

	if (*(s + 1) == 'c')
		return write(1, &va_arg(paras, int), 1);
	else if (*(s + 1) == 's')
	{
		str = va_arg(paras, char *);
		if (str)
			return write(1, str, ft_strlen(str));
		return write(1, "(null)", 6);
	}
	else if (*(s + 1) == 'd' || *(s + 1) == 'i')
	{
		str = ft_itoa(va_arg(paras, int));
		if (!str)
			return -1;
		len += write(1, str, ft_strlen(str));
		free(str);
	}
	else if (*(s + 1) == 'x')
		return ft_putnbr_base(va_arg(paras, int), "0123456789abcdef");
	else if (*(s + 1) == 'X')
		return ft_putnbr_base(va_arg(paras, int), "0123456789ABCDEF");
	else if (*(s + 1) == 'p')
	{
		ptr = va_arg(paras, void *);
		if (!ptr)
			return write(1, "(nil)", 5);
		return write(1, "0x", 2) + ft_putnbr_base_size_t((size_t)ptr, "0123456789abcdef");
	}
	else if (*(s + 1) == 'u')
	{
		ptr = ft_utoa(va_arg(paras, unsigned int));
		if (!ptr)
			return -1;
		len += write(1, ptr, ft_strlen(ptr));
		free(ptr);
	}
	else if (*(s + 1) == '%')
		return write(1, "%", 1);
	else
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
		{
			write(1, s, 1);
			len++;
		}
		s++;
	}
	va_end(paras);
	return (len);
}
