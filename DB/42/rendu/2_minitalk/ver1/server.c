#include "minitalk.h"

byte	*bitstream;
int		count;

void handler(int sig, siginfo_t *info, void *context)
{
	const int	sender = info->si_pid;

	(void) context;
	(void) sender;

	*bitstream = (*bitstream << 1) + sig/11;
	count++;
	if (count == 8)
	{

		write(1, bitstream, 1);
		count = 0;
	}
	// 비트가 하나씩 밀릴 때마다, 아스키코드 문자의 크기는 2배씩 증가
}

int main(int argc, char *argv[])
{
	const int 	pid = getpid();
	t_sigma		sigma;

	(void) argv;
	if (argc != 1)
		return (0 * ft_printf("매개변수 없이 ./server만 입력해주세요."));

	ft_printf("%d\n", pid);

	bitstream = (byte *)malloc(77777);
	ft_memset(bitstream, 0, 77777);

	sigma.sa_flags = SA_SIGINFO;
	sigma.sa_sigaction = handler;

	sigaction(SIGUSR1, &sigma, NULL);
	sigaction(SIGUSR2, &sigma, NULL);

	while(1)
		pause();

	return 0;
}
