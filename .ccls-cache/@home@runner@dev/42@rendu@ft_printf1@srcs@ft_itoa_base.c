
#include "ft_printf.h"

char	*ft_itoa_base(long long nbr, char *base)
{
	char				*output;
	size_t				nbr_len;
	size_t				base_len;

	base_len = ft_strlen(base);
	nbr_len = ft_intlen_base(nbr, base_len);
	output = (char *)calloc((nbr_len + 1), sizeof(char));
	if (!output)
		return (NULL);
	while (nbr_len-- > 0)
	{
		output[nbr_len] = base[nbr % base_len];
		nbr /= base_len;
	}
	return (output);
}
