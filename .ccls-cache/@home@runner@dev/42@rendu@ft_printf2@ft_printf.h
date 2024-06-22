#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>

# define SMALL "0123456789abcdef"
# define BIG "0123456789ABCDEF"

size_t			ft_strlen(const char *s);
char			*ft_itoa(int n);
char			*ft_itoa_base_unsigned(unsigned int n);
unsigned int	ft_putnbr_base(unsigned int nbr, const char *base);
size_t			ft_putnbr_base_size_t(size_t nbr, const char *base);
int				ft_printf(const char *s, ...);

#endif