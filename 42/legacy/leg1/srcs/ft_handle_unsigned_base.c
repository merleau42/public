#include "ft_printf.h"

static void	ft_print_unsigned_base(unsigned int num, char *base, size_t *ret)
{
	char	*output;

	output = NULL;
	if (num == 0)
	{
		ft_putchar_fd('0', 1);
		*ret += 1;
	}
	else
	{
		output = ft_itoa_base(num, base);
		ft_putstr_fd(output, 1);
		if (output)
			free(output);
	}
}

void	ft_handle_unsigned_base(const char **str, size_t *ret, \
		va_list *ap, char *base)
{
	int				arg;
	unsigned int	converted;

	arg = (unsigned int)va_arg(*ap, int);
	converted = (unsigned int)arg;
	ft_print_unsigned_base(converted, base, ret);
	*ret += ft_unsigned_intlen_base(converted, ft_strlen(base));
	*str += 1;
}
