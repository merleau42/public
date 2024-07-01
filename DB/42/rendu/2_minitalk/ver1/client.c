#include "minitalk.h"

int main(int argc, char *argv[])
{
	if (argc != 3)
		return (0 * ft_printf("문법 → ./client [서버의 PID] [문자메시지]"));
	ft_printf("%s", argv[1]);



	return 0;
}