/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keunkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 23:11:54 by keunkim           #+#    #+#             */
/*   Updated: 2023/07/22 23:15:23 by keunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	ft_putchar(char *c);

void	rush03(int x, int y)
{
	int	i;
	int	j;

	if (x <= 0 || y <= 0)
		write(1, "invalid input!!\n", 16);
	i = 0;
	while (i++ <= y - 1)
	{
		j = 0;
		while (j++ <= x - 1)
		{
			if ((i == 1 && j == 1) || (i == y && j == 1))
				ft_putchar("A");
			else if ((i == 1 || i == y) && j == x && j != 1)
				ft_putchar("C");
			else if ((i != 1 && i != y) && j != 1 && j != x)
				ft_putchar(" ");
			else
				ft_putchar("B");
		}
		ft_putchar("\n");
	}
}
