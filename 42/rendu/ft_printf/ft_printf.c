#include "ft_printf.h"

static void	ft_process(va_list paras, const char *s, size_t *len)
{
	char	c;
	char	*str;
	char	chr;
	int	nums_int;
	char *ptr;

	c = *(s + 1);
	if (c == 'c')
	{
		chr = va_arg(paras, int);
		write(1, &chr, 1);
		*len += 1;
	}
	else if (c == 's')
	{
		str = va_arg(paras, char *);
		if (str)
		{
			write(1, str, ft_strlen(str));
			*len += ft_strlen(str);
			return ;
		}
		write(1, "(null)", 6);
		*len += 6;
	}
	else if (c == 'd' || c == 'i')
	{
		str = ft_itoa(va_arg(paras, int));
		if (!str)
		{
			*len = -1;
			return ;
		}
		write(1, str, ft_strlen(str));
		*len += ft_strlen(str);
		free(str);
	}
	else if (c == 'x')
		*len += ft_putnbr_base(va_arg(paras, int), "0123456789abcdef");
	else if (c == 'X')
		*len += ft_putnbr_base(va_arg(paras, int), "0123456789ABCDEF");
	else if (c == 'p')
	{
		ptr = va_arg(paras, void *);
		if (!ptr)
		{
			write(1, "(nil)", 5);
			*len += 5;
			return ;
		}
		write(1, "0x", 2);
		*len += 2 + ft_putnbr_base_size_t((size_t)ptr, "0123456789abcdef");
	}
	else if (c == 'u')
	{
		nums_unsign = ;
		ptr = ft_utoa(va_arg(paras, unsigned int));
		if (!ptr)
		{
			*len = -1;
			return ;
		}
		write(1, ptr, ft_strlen(ptr));
		*len += ft_strlen(ptr);
		free(ptr);
	}
	else if (c == '%')
	{
		write(1, "%", 1);
		*len += 1;
	}
	else
		*len = -1;
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
			ft_process(paras, s, &len);
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
