
#include "ft_printf.h"

size_t	ft_intlen_base(long long ll, size_t base_len)
{
	size_t	ret;

	ret = 0;
	while (ll != 0)
	{
		ll /= base_len;
		ret ++;
	}
	return (ret);
}
