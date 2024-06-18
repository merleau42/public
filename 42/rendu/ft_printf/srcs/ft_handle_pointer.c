
#include "ft_printf.h"

void	ft_handle_pointer(const char **str, size_t *ret, va_list *ap)
{
	char				*arg;
	char				*hex_address;
	unsigned long long	address;

	arg = va_arg(*ap, char *);
	if (arg == NULL)
	{
		arg = NIL_OUTPUT;
		ft_putstr_fd(arg, 1);
		*ret += (int)ft_strlen(arg);
	}
	else
	{
		address = (unsigned long long)arg;
		hex_address = ft_itoa_base(address, "0123456789abcdef");
		if (hex_address)
		{
			ft_putstr_fd("0x", 1);
			ft_putstr_fd(hex_address, 1);
			*ret += ft_strlen(hex_address) + 2;
			free(hex_address);
		}
	}
	*str += 1;
}
