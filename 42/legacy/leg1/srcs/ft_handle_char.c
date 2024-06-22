
#include "ft_printf.h"

void	ft_handle_char(const char **str, size_t *ret, va_list *ap)
{
	char	arg;

	arg = (char)va_arg(*ap, int);
	ft_putchar_fd(arg, 1);
	*ret += (int)ft_strlen(&arg);
	if (arg == '\0')
		*ret += 1;
	*str += 1;
}
