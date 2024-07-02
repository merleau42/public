#include "minitalk.h"

void handler(int sig, siginfo_t *info, void *context)
{
	(void) context;
	ft_printf("\ngot from %d: ", info->si_pid);
	if (sig == SIGUSR1)
		ft_printf("SIGUSR1");
	if (sig == SIGUSR2)
		ft_printf("SIGUSR2");
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
