/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keunykim <keunykim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 23:42:41 by keunykim          #+#    #+#             */
/*   Updated: 2024/06/28 23:42:42 by keunykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_data	ascii;


void sig_action(int signum, siginfo_t *info, void *context)
{
  if (signum == SIGUSR1)
  {
    ascii.ascii = ascii.ascii << 1;
  }
  else if (signum == SIGUSR2)
  {
    ascii.ascii = ascii.ascii << 1;
    ascii.ascii++;
  }
  ascii.bit_count++;
  if (ascii.bit_count == 7)
  {
    ascii.buff[ascii.buff_idx] = ascii.ascii;
    // write(1, &ascii.ascii, 1);
    ascii.buff_idx++;
    if (ascii.buff_idx > 99 || ascii.ascii == 0)
    {
      write(1, ascii.buff, ascii.buff_idx);
      ascii.buff_idx = 0;
    }
    ascii.bit_count = 0;
    ascii.ascii = 0;
    usleep(200);
    kill(info->si_pid, SIGUSR2);
  }
  // info->si_pid = 0;
  context = (void *)0;
}

int main() {
  struct sigaction	sig1;

  ascii.ascii = 0;
  ascii.bit_count = 0;
  ascii.buff_idx = 0;
  // sig1.sa_handler = sig_handler;
  // sigemptyset(&sig1.sa_mask);
  // sig1.sa_flags = 0;
  sig1.sa_sigaction = sig_action;
  // sigemptyset(&sig1.sa_mask);
  sig1.sa_flags = SA_SIGINFO;
  printf("%d\n", getpid());
  sigaction(SIGUSR1, &sig1, NULL);
  sigaction(SIGUSR2, &sig1, NULL);
  while (1)
  {
    pause();
  }
  return (0);
}