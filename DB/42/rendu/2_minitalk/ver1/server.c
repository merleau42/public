#include "minitalk.h"

struct s_equence	bit;

static void	handler(int sig, siginfo_t *info, void *context)
{
	const int	reply = info->si_pid;

	(void) context;
	bit.stream[bit.count / 8] = (bit.stream[bit.count / 8] << 1) + sig / 11;
	bit.count++;
	if (bit.count % 8 == 0)
	{
		if (bit.stream[(bit.count - 1) / 8] == '\0')
		{
			write(1, bit.stream, bit.count / 8);
			bit.count = 0;
		}
	}
	usleep(40);
	kill(reply, "\n\f처리완료! 이제 다음 비트를 보내라우"[sig / 11]);
}

int	main(int argc, char *argv[])
{
	const int	pid = getpid();
	t_sigma		sigma;

	if (argc != 1)
		return (0 * ft_printf("매개변수 없이 ./server만 입력해주세요."));
	ft_printf("실행 중인 프로그램의( %s ) 프로세스 아이디( %d )\n", argv[0], pid);
	bit.stream = ft_memset(malloc(1000000), 0, 1000000);
	bit.count = 0;
	sigma.sa_flags = SA_SIGINFO;
	sigma.sa_sigaction = handler;
	sigaction(SIGUSR1, &sigma, NULL);
	sigaction(SIGUSR2, &sigma, NULL);
	while (1)
		pause();
	return (0);
}
