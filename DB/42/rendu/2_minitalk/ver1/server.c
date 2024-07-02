#include "minitalk.h"

void handler(int sig, siginfo_t *info, void *context)
{
	const int from = info->si_pid;

	(void) context;
	if (sig == SIGUSR1)
		ft_printf("\ngot SIGUSR1");
	if (sig == SIGUSR2)
		ft_printf("\ngot SIGUSR2");
	ft_printf("\ngot from %d", from);
}

int main()
{
	const int 	pid = getpid();
	t_sigma		sigma;

	ft_printf("%d", pid);

	sigma.sa_flags = SA_SIGINFO;
	sigma.sa_sigaction = handler;

	sigaction(SIGUSR1, &sigma, NULL);
	sigaction(SIGUSR2, &sigma, NULL);

	while(1)
		pause();

	return 0;
}
