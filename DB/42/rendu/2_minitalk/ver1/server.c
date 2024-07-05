#include "minitalk.h"

struct s_equence	g_bit;

static void	handler(int sig, siginfo_t *info, void *context)
{
	const int	reply = info->si_pid;

	*(g_bit.stream) = *(g_bit.stream) * 2 + (sig / 11);
	g_bit.count++;
	if (g_bit.count % 8 == 0)
	{
		(g_bit.stream)++;
		if (*(g_bit.stream - 1) == '\0')
		{
			write(1, g_bit.stream - g_bit.count / 8, g_bit.count / 8);
			g_bit.count = 0;
		}
	}
	usleep(40);
	kill(reply, "\12\14 처리완료! 이제 다음 비트를 보내시옹!"[sig / 11]);
	(void) context;
}

int	main(int argc, char *argv[])
{
	const int	pid = getpid();
	t_sigma		sigma;

	if (argc != 1)
		return (0 * ft_printf("매개변수 없이 ./server만 입력해주세요."));
	ft_printf("실행 중인 프로그램의( %s ) 프로세스 아이디( %d )\n", argv[0], pid);
	g_bit.stream = ft_memset(malloc(1000000), 0, 1000000);
	g_bit.rewind = g_bit.stream;
	g_bit.count = 0;
	sigma.sa_flags = SA_SIGINFO;
	sigma.sa_sigaction = handler;
	sigaction(SIGUSR1, &sigma, NULL);
	sigaction(SIGUSR2, &sigma, NULL);
	while (1)
		pause();
	return (0);
}
