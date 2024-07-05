/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keunykim <keunykim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 05:15:45 by keunykim          #+#    #+#             */
/*   Updated: 2024/07/06 05:15:45 by keunykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <stdlib.h>
# include <signal.h>
# include <unistd.h> 
# include <stdarg.h>

typedef struct sigaction	t_sigma;

int		ft_printf(const char *s, ...);
int		ft_atoi(const char *nptr);
void	*ft_memset(void *s, int c, size_t n);

struct s_equence
{
	char	*stream;
	int		count;
};
#endif