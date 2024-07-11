#include "minitalk.h"

int	count;

static void	handler(int sig)
{
	if (sig == SIGUSR1 || sig == SIGUSR2)
		ft_printf("%d", sig / 11);
}

static void	send_byte(int pid, unsigned char byte)
{
	int	i;

	ft_printf("%d\t%c\t%d\t", byte, byte, ++count);
	i = 0;
	while (i < 8)
	{
		kill(pid, 10 + 2 * ((byte >> (7 - i)) & 1));
		pause();
		i++;
	}
	ft_printf("\n");
}

int	main(int argc, char *argv[])
{
	char	*msg;
	int		pid;

	if (argc != 3)
		return (0 * ft_printf("사용법: ./client [서버PID] [문자메시지]\n"));
	ft_printf("실행 중인 프로그램의( %s ) 프로세스 아이디( %d )\n", argv[0], getpid());
	pid = ft_atoi(argv[1]);
	msg = argv[2];
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while (*msg != '\0')
		send_byte(pid, *(msg++));
	send_byte(pid, '\0');
	ft_printf("메시지 전송 완료... 1초 대기\n");
	sleep(1);
	return (0);
}
