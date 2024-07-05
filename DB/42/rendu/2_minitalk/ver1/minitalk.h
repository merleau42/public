#ifndef MINITALK_H
# define MINITALK_H
# include <stdlib.h>
# include <signal.h>
# include <unistd.h> 
# include <stdarg.h>

typedef struct sigaction	t_sigma;

int		ft_printf(const char *s, ...);
int		ft_atoi(const char *nptr);
void	*ft_memset(void *s, int c, size_t n);

struct s_equence
{
	char	*stream;
	int		count;
};
#endif

/*
핸들러 구조체는 <signal.h>에 정의되어있음.
struct sigaction {
	void     (*sa_handler)(int);
	void     (*sa_sigaction)(int, siginfo_t *, void *);
	sigset_t   sa_mask;
	int        sa_flags;
	void     (*sa_restorer)(void);
};
*/