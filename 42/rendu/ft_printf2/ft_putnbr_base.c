
#include "ft_printf.h"

unsigned int	ft_putnbr_base(unsigned int nbr, const char *base)
{
	char			output[65];
	unsigned int	base_len;
	unsigned int	i;

	base_len = ft_strlen(base);
	if (nbr == 0)
	{
		write(1, &base[0], 1);
		return (1);
	}
	i = 0;
	while (nbr != 0)
	{
		output[i++] = base[nbr % base_len];
		nbr /= base_len;
	}
	base_len = i;
	while (i--)
	{
		write(1, &output[i], 1);
	}
	return (base_len);
}
