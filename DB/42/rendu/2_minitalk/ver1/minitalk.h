#ifndef MINITALK_H
# define MINITALK_H
# include <stdlib.h>
# include <signal.h>
# include <unistd.h> 
# include <stdarg.h>

int	ft_printf(const char *s, ...);
int	ft_atoi(const char *nptr);

typedef struct sigaction t_sigma;

#endif