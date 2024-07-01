#ifndef MINITALK_H
# define MINITALK_H
# include <stdlib.h>
# include <signal.h>
# include <unistd.h> 
# include <stdarg.h>

// ft_printf
int				ft_printf(const char *s, ...);
static void		ft_process(va_list paras, const char *s, int *len);
static size_t	ft_putnbr(size_t nbr, char *base, int type);
static size_t	ft_putchar(int nbr);
static char		*ft_strchr(const char *s, int c);

#endif