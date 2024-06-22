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
	void	*ptr;

	if (*(s + 1) == '%')
		return (write(1, "%", 1));
	if (*(s + 1) == 'd' || *(s + 1) == 'i')
		return (ft_putnbr_base(va_arg(paras, int), "0123456789"));
	if (*(s + 1) == 'u')
		return (ft_putnbr_base_uint(va_arg(paras, int), "0123456789"));
	if (*(s + 1) == 'x')
		return (ft_putnbr_base_uint(va_arg(paras, int), "0123456789abcdef"));
	if (*(s + 1) == 'X')
		return (ft_putnbr_base_uint(va_arg(paras, int), "0123456789ABCDEF"));
	if (*(s + 1) == 'c')
		return (write(1, ptr, 1));
	if (*(s + 1) == 's' || *(s + 1) == 'p')
		ptr = va_arg(paras, void *);
	if (*(s + 1) == 's' && ptr)
		return (write(1, ptr, ft_strlen(ptr)));
	if (*(s + 1) == 'p' && ptr)
		return (write(1, "0x", 2) + ft_putnbr_base_size_t(ptr, "0123456789abcdef"));
	if (*(s + 1) == 's' && !ptr)
		return (write(1, "(null)", 6));
	if (*(s + 1) == 'p' && !ptr)
		return (write(1, "(nil)", 5));
	return (-1);
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
