#include "minitalk.h"

void handler(int sig)
{
	if (sig == SIGUSR1)
		ft_printf("SIGUSR1\n");
	if (sig == SIGUSR2)
		ft_printf("SIGUSR1\n");
}

int main()
{
	const int 	pid = getpid();
	// char		*bitstream[100000];
	t_sigma		sig;

	sig.sa_handler = handler;
	sigaction(SIGUSR1, &sig);

	pause();

	ft_printf("%d", pid);

	return 0;
}
