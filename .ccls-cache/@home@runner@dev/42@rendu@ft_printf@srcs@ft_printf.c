#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	size_t	ret;
	va_list	ap;

	ret = 0;
	if (str == NULL)
		ret = -1;
	va_start(ap, str);
	while (*str != '\0' && ret != -1)
	{
		if (*str == '%')
			ft_read_spec(&str, &ret, &ap);
		else if (write(1, *str, 1) != -1)
			ret++;
		else
			ret = -1;
		str++;
	}
	va_end(ap);
	return (ret);
}
