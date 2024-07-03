#include "minitalk.h"

void handler(int sig, siginfo_t *info, void *context)
{
	const int	sender = info->si_pid;

	(void) context;
	ft_printf("\ngot from %d: ", sender);
	if (sig == SIGUSR1)
		ft_printf("SIGUSR1");
	if (sig == SIGUSR2)
		ft_printf("SIGUSR2");
}

int main(int argc, char *argv[])
{
	const int 	pid = getpid();
	t_sigma		sigma;

	// if (argc != 1)
		// return (0 * ft_printf("사용법: ./server"));

	ft_printf("%d", pid);

	sigma.sa_flags = SA_SIGINFO;
	sigma.sa_sigaction = handler;

	sigaction(SIGUSR1, &sigma, NULL);
	sigaction(SIGUSR2, &sigma, NULL);

	while(1)
		pause();

	return 0;
}
