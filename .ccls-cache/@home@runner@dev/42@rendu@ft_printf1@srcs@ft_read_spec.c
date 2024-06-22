
#include "ft_printf.h"

void	ft_read_spec(const char	**str, size_t *ret, va_list *ap)
{
	char	*format;

	format = (char *)(*str + 1);
	if (*format == 's')
		ft_handle_str(str, ret, ap);
	else if (*format == 'c')
		ft_handle_char(str, ret, ap);
	else if (*format == '%')
		ft_handle_percent(str, ret);
	else if (*format == 'p')
		ft_handle_pointer(str, ret, ap);
	else if (*format == 'i' || *format == 'd')
		ft_handle_decimal(str, ret, ap);
	else if (*format == 'u')
		ft_handle_unsigned_base(str, ret, ap, BASE_DECIMAL);
	else if (*format == 'x')
		ft_handle_unsigned_base(str, ret, ap, BASE_HEXA_LOWER);
	else if (*format == 'X')
		ft_handle_unsigned_base(str, ret, ap, BASE_HEXA_UPPER);
}
