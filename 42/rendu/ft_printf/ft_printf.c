#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	const char	*rewind;

	rewind = s;
	while (*s != '\0')
		s++;
	return (s - rewind);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return ((char *) s + i);
		i++;
	}
	if (c == '\0')
		return ((char *) s + i);
	else
		return (NULL);
}

size_t	ft_putchar(int nbr)
{
	return (write(1, &nbr, 1));
}

void ft_process(va_list paras, const char *s, int *len)
{
	void	*ptr;

	if (*(s + 1) == '%')
		*len += write(1, "%", 1);
	if (*(s + 1) == 'd' || *(s + 1) == 'i')
		*len += ft_putnbr_base(va_arg(paras, int), "0123456789");
	if (*(s + 1) == 'u')
		*len += ft_putnbr_base_uint(va_arg(paras, int), "0123456789");
	if (*(s + 1) == 'x')
		*len += ft_putnbr_base_uint(va_arg(paras, int), HEXLOWER);
	if (*(s + 1) == 'X')
		*len += ft_putnbr_base_uint(va_arg(paras, int), HEXUPPER);
	if (*(s + 1) == 'c')
		*len += ft_putchar(va_arg(paras, int));
	if (*(s + 1) == 's' || *(s + 1) == 'p')
		ptr = va_arg(paras, void *);
	if (*(s + 1) == 's' && ptr)
		*len += write(1, ptr, ft_strlen(ptr));
	if (*(s + 1) == 'p' && ptr)
		*len += write(1, "0x", 2) + ft_putnbr_base_szt((size_t)ptr, HEXLOWER);
	if (*(s + 1) == 's' && !ptr)
		*len += write(1, "(null)", 6);
	if (*(s + 1) == 'p' && !ptr)
		*len += write(1, "(nil)", 5);
	if (!ft_strchr("duxXcsp%", *(s + 1)))
		*len = -1;
}

int	ft_printf(const char *s, ...)
{
	va_list	paras;
	int		len;

	va_start(paras, s);
	len = 0;
	while (*s)
	{
		if (*s == '%')
		{
			ft_process(paras, s, &len);
			if (len == -1)
			{
				va_end(paras);
				return (-1);
			}
			s++;
		}
		else
			len += write(1, s, 1);
		s++;
	}
	va_end(paras);
	return (len);
}

int main()
{
	//: %d
	// ft_printf("꾸%d%d이지롱\n", 9990, 777);
	// ft_printf("%d이지롱\n", 1);
	// ft_printf("%d이거든\n", 2);
	// ft_printf("%d이거든\n", 10);
	// ft_printf("%d이궈거든\n", 12);
	// ft_printf("%d이궈거든\n", 7777);
	// ft_printf("%d이지\n", 2147483646);
	// ft_printf("%d이지\n", 2147483647);
	// ft_printf("%d이렴\n", -1);
	// ft_printf("%d이렴\n", -2);
	// ft_printf("%d이런\n", -10);
	// ft_printf("%d이런\n", -12);
	// ft_printf("%d이다\n", -7777);
	// ft_printf("%d이다\n", -2147483647);
	// ft_printf("%d입니다\n", -2147483648);

	//: %c
	// ft_printf("%c", 'H');
	// ft_printf("%c", 'E');
	// ft_printf("%c", 'L');
	// ft_printf("%c", 'L');
	// ft_printf("%c", 'O');
	// ft_printf("%c", '\n');
	// ft_printf("%c", '!');
	// ft_printf("%c", '?');
}