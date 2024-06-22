
#include "ft_printf.h"

void	ft_handle_percent(const char **str, size_t *ret)
{
	ft_putchar_fd(**str, 1);
	*str += 1;
	*ret += 1;
}
