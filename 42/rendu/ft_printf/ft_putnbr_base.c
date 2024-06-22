#include "ft_printf.h"
// 피신 풋넘버 베이스 개조
size_t	ft_putnbr_base(int nbr, char *base)
{
	char		conv[65];
	char		front;
	int			index;
	const int	nary = ft_strlen(base);

	if (nbr == -2147483648)
		return (write(1, "-2147483648", 11));
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = -nbr;
	}
	index = 65;
	front = index - 1;
	while (index--)
	{
		conv[index] = base[nbr % nary];
		nbr = nbr / nary;
		if (conv[index] != base[0])
			front = index;
	}
	return (write(1, conv + front, 65 - front));
}

size_t	ft_putnbr_base_uint(unsigned int nbr, char *base)
{
	char		conv[65];
	char		front;
	int			index;
	const int	nary = ft_strlen(base);

	index = 65;
	front = index - 1;
	while (index--)
	{
		conv[index] = base[nbr % nary];
		nbr = nbr / nary;
		if (conv[index] != base[0])
			front = index;
	}
	return (write(1, conv + front, 65 - front));
}

size_t	ft_putnbr_base_szt(size_t nbr, char *base)
{
	char		conv[65];
	char		front;
	int			index;
	const int	nary = ft_strlen(base);

	index = 65;
	front = index - 1;
	while (index--)
	{
		conv[index] = base[nbr % nary];
		nbr = nbr / nary;
		if (conv[index] != base[0])
			front = index;
	}
	return (write(1, conv + front, 65 - front));
}

// int main()
// {
// 	ft_putnbr_base(-1, "0123456789abcdef");
// 	write(1,"\n",1);
// 	ft_putnbr_base_uint(-1, "0123456789abcdef");
// 	write(1,"\n",1);
// 	ft_putnbr_base_llu(-1, "0123456789abcdef");
// 	write(1,"\n\n",2);
// 	ft_putnbr_base(2147483648, "0123456789");
// 	write(1,"\n",1);
// 	ft_putnbr_base_uint(2147483648, "0123456789");
// 	write(1,"\n",1);
// 	ft_putnbr_base_llu(2147483648, "0123456789");
// 	return 0;
// }