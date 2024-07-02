#include "minitalk.h"

int main(int argc, char *argv[])
{
	int		pid;
	// char*	msg;

	// if (argc != 3)
		// return (0 * ft_printf("형식:  ./client [서버PID] [문자메시지]"));

	pid = ft_atoi(argv[1]);
	// msg = argv[2];

	ft_printf("%d", argc);
	
	kill(pid, SIGUSR1);
	// sleep(2);
	// kill(pid, SIGUSR2);

	return 0;
}
