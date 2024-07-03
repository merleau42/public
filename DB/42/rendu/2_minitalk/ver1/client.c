#include "minitalk.h"

int main(int argc, char *argv[])
{
	int		pid;
	char*	msg;

	if (argc != 3)
		return (0 * ft_printf("사용법: ./client [서버PID] [문자메시지]\n"));

	pid = ft_atoi(argv[1]);
	msg = argv[2];

	int		i;

	while(*msg != '\0')
	{
		i = 0;
		while(i < 8)
		{
			kill(pid, 10 + 2 * ((*msg >> (7-i)) & 1));
			usleep(100);
			i++;
		}
		msg++;
	}

	return 0;
}
