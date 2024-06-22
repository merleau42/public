#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define HEXLOWER "0123456789abcdef"
# define HEXUPPER "0123456789ABCDEF"
# include <stdarg.h>
// # include <stdlib.h>
# include <unistd.h>
# include <stdint.h>

int		ft_printf(const char*, ...);
void		ft_process(va_list, const char*, int*);
size_t	ft_strlen(const char*);
char	*ft_strchr(const char*, int);
size_t	ft_putnbr_base(int nbr, char*);
size_t	ft_putnbr_base_uint(unsigned int nbr, char*);
size_t	ft_putnbr_base_szt(size_t nbr, char*);

#endif