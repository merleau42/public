
#include "libft.h"

static size_t	ft_num_size(long long int n)
{
	size_t	ret;

	ret = 0;
	while (n != 0)
	{
		n = n / 10;
		ret++;
	}
	return (ret);
}

static int	ft_get_square(int base, size_t exponent)
{
	int		ret;
	size_t	index;

	ret = 1;
	index = 0;
	while (index < exponent)
	{
		ret *= base;
		index++;
	}
	return (ret);
}

void	ft_putnbr_fd(int n, int fd)
{
	size_t	index;
	int		copied;
	char	character;

	copied = n;
	index = ft_num_size(copied);
	if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		copied = ((long long int)n * -1);
	}
	else if (n == 0)
		ft_putchar_fd('0', fd);
	while (copied > 0)
	{
		character = (char)((copied / ft_get_square(10, --index)) + '0');
		write(fd, &character, 1);
		copied = copied % ft_get_square(10, index);
	}
	if (index > 0 && n != -2147483648)
		ft_putchar_fd('0', fd);
}
