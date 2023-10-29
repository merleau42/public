/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeondcho <yeondcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 22:08:04 by yeondcho           #+#    #+#            */
/*   Updated: 2023/07/22 23:12:56 by yeondcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	ft_putchar(char *c);

void	rush04(int x, int y)
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
			if (i * j < 2 | i * j == x * y & (j > 1 | i < 2) & (j != x | i > 1))
				ft_putchar("A");
			else if (i == y & j == 1 & j * y > 1 | j == x & i == 1 & j * y > 1)
				ft_putchar("C");
			else if ((i != 1 && i != y) && j != 1 && j != x)
				ft_putchar(" ");
			else
				ft_putchar("B");
		}
		ft_putchar("\n");
	}
}
