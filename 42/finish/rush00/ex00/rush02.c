/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keunykim <keunykim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 09:17:51 by keunykim          #+#    #+#             */
/*   Updated: 2023/12/03 11:52:18 by keunykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char *preset, int put);

void	rush02(int x, int y)
{
	int	i;
	int	put;

	i = 0;
	if (x <= 0 || y <= 0)
	{
		write(1, "Error : The parameters must be a positive integer.\n", 51);
		return ;
	}
	while (i++ < x * y)
	{
		put = 4;
		put += ((i - 1) % x > 0) + ((i - 1) % x == x - 1);
		put += -3 * ((i - 1) / x == 0) + 3 * ((i - 1) / x == y - 1);
		put += -(x == 1) - 3 * (y == 1);
		ft_putchar("0ABAB BCBC", put);
		if (i % x == 0)
			write(1, "\n", 1);
	}
}
