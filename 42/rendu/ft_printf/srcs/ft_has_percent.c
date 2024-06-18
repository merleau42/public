
#include "ft_printf.h"

int	ft_has_percent(const char *str)
{
	if (*str == PERCENT)
		return (TRUE);
	return (FALSE);
}
