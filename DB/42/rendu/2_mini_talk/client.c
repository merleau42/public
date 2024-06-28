#include "minitalk.h"

void	signal_chk()
{
  usleep(100);
}

int main( int argc, char *argv[])
{
  int	pid;
  int	ascii;
  int	i;
  int	j;
  struct sigaction	sig;

  sig.sa_handler = signal_chk;
  // sigemptyset(&sig.sa_mask);
  sig.sa_flags = 0;
  if (argc < 2)
    printf( "사용법: ./client [프로세스 ID] [메세지]\n");
  else
  {
    sigaction(SIGUSR1, &sig, NULL);
    sigaction(SIGUSR2, &sig, NULL);
    pid = ft_atoi(argv[1]);
    for(i = 0; i < (int)ft_strlen(argv[2]); i++)
    {
      ascii = (int)argv[2][i];
      j = 6;
      while (j >= 0)
      {
        if (((1 << j) & ascii) == 0)
          kill(pid, SIGUSR1);
        else
          kill(pid, SIGUSR2);
        if (j > 0)
          usleep(50);
        j--;
      }
      pause();
    }
    for(i = 0; i < 7; i++)
    {
      kill(pid, SIGUSR1);
      usleep(50);
    }
  sleep(2);
  ft_printf("wait..\n");
  sleep(1);
  }
  return (0);
}