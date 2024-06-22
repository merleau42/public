#include "ft_printf.h"

static void	print_percent_4(va_list paras, char c, size_t *len)
{
	unsigned int	nums_unsign;
	void			*ptr;

	if (c == 'u')
	{
		nums_unsign = va_arg(paras, unsigned int);
		ptr = ft_itoa_unsigned(nums_unsign);
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

static void	print_percent_3(va_list paras, char c, size_t *len)
{
	void			*ptr;
	size_t			arg_addr;
	size_t			addr_len;

	if (c == 'p')
	{
		ptr = va_arg(paras, void *);
		if (!ptr)
		{
			write(1, "(nil)", 5);
			*len += 5;
			return ;
		}
		arg_addr = (size_t)ptr;
		write(1, "0x", 2);
		addr_len = ft_putnbr_base_size_t(arg_addr, SMALL);
		*len += addr_len + 2;
	}
	else
		print_percent_4(paras, c, len);
}

static void	print_percent_2(va_list paras, char c, size_t *len)
{
	int			nums_int;
	char		*str;

	if (c != 'd' && c != 'i' && c != 'x' && c != 'X')
		return (print_percent_3(paras, c, len));
	nums_int = va_arg(paras, int);
	if (c == 'd' || c == 'i')
	{
		str = ft_itoa_signed(nums_int);
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
		*len += ft_putnbr_base(nums_int, SMALL);
	else if (c == 'X')
		*len += ft_putnbr_base(nums_int, BIG);
}

static void	print_percent_1(va_list paras, const char *s, size_t *len)
{
	char	c;
	char	*str;
	char	chr;

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
	else
		print_percent_2(paras, c, len);
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
			print_percent_1(paras, s, &len);
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
