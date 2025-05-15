/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keunykim <keunykim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 23:50:27 by keunykim          #+#    #+#             */
/*   Updated: 2024/04/04 22:37:54 by keunykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	conv[10];
	char	start;
	int		i;

	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			write(fd, "-", 1);
			n = -n;
		}
		i = 10;
		start = 9;
		while (i--)
		{
			conv[i] = n % 10 + '0';
			n = n / 10;
			if (conv[i] != '0')
				start = i;
		}
		write(fd, conv + start, 10 - start);
	}	
}
