#include "minitalk.h"

byte	*bitstream;
int		count;

static void handler(int sig, siginfo_t *info, void *context)
{
	const int	reply = info->si_pid;

	(void) context;

	*bitstream = (*bitstream << 1) + sig/11;
	count++;
	if (count % 8 == 0)
	{
		if (*bitstream < 128)
		{
			write(1, bitstream, 1);
			bitstream++;
		}
	}

	usleep(50);
	kill(reply, "\n처리완료! 다음 비트를 보내세요"[0]);
}

int main(int argc, char *argv[])
{
	const int 	pid = getpid();
	t_sigma		sigma;

	if (argc != 1)
		return (0 * ft_printf("매개변수 없이 ./server만 입력해주세요."));
	ft_printf("실행된 프로그램의( %s ) 프로세스 아이디( %d )\n", argv[0], pid);
	bitstream = (byte *)malloc(77777);
	ft_memset(bitstream, 0, 77777);
	bitstream[0] = 255;
	bitstream++;

	sigma.sa_flags = SA_SIGINFO;
	sigma.sa_sigaction = handler;

	sigaction(SIGUSR1, &sigma, NULL);
	sigaction(SIGUSR2, &sigma, NULL);

	while(1)
		pause();

	return 0;
}
