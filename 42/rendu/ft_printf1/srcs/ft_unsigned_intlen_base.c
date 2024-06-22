
#include "ft_printf.h"

size_t	ft_unsigned_intlen_base(unsigned long long ull, size_t base_len)
{
	size_t	ret;

	ret = 0;
	while (ull != 0)
	{
		ull /= base_len;
		ret++;
	}
	return (ret);
}
