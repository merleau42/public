/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keunykim <keunykim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 09:18:00 by keunykim          #+#    #+#             */
/*   Updated: 2023/12/03 13:11:37 by keunykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	rush00(int x, int y);
void	rush01(int x, int y);
void	rush02(int x, int y);
void	rush03(int x, int y);
void	rush04(int x, int y);

int	main(void)
{	
	int	i;
	int	j;

	i = '0' - 1;
	while (i++ <= '4')
	{
		j = '0' - 1;
		while (j++ <= '4')
		{
			write(1, "\n\nrush(", 7);
			write(1, &i, 1);
			write(1, ",", 1);
			write(1, &j, 1);
			write(1, ")\n", 2);
			rush00(i - '0', j - '0');
			write(1, "\n", 1);
			rush01(i - '0', j - '0');
			rush02(i - '0', j - '0');
			write(1, "\n", 1);
			rush03(i - '0', j - '0');
			write(1, "\n", 1);
			rush04(i - '0', j - '0');
		}
	}
	return (0);
}
