
#include "ft_printf.h"

void	ft_handle_str(const char **str, size_t *ret, va_list *ap)
{
	char	*arg;

	arg = va_arg(*ap, char *);
	if (arg == NULL)
		arg = NULL_OUTPUT;
	ft_putstr_fd(arg, 1);
	*ret += (int)ft_strlen(arg);
	*str += 1;
}
