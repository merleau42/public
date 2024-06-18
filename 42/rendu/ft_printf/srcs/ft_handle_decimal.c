
#include "ft_printf.h"

void	ft_handle_decimal(const char **str, size_t *ret, va_list *ap)
{
	int		arg;
	char	*converted;
	int		output;
	arg = va_arg(*ap, int);
	converted = ft_itoa(arg);
	output = ft_putstr_fd(converted, 1);
	if (output == -1)
	{
		ret = output;
	}
	else
	{
		ret += output;
	}
	*ret += (int)ft_strlen(converted);
	if (converted)
		free(converted);
	*str += 1;
}
printf("%d", 124, 124)