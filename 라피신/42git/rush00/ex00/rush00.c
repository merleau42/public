/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keunkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 22:08:04 by keunkim           #+#    #+#             */
/*   Updated: 2023/07/22 23:07:31 by yeondcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	ft_putchar(char *c);

void	rush00(int x, int y)
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
			if ((i == 1 || i == y) && (j == 1 || j == x))
				ft_putchar("o");
			if ((i == 1 || i == y) && j != 1 && j != x)
				ft_putchar("-");
			if ((i != 1 && i != y) && (j == x || j == 1))
				ft_putchar("|");
			if ((i != 1 && i != y) && j != 1 && j != x)
				ft_putchar(" ");
		}
		ft_putchar("\n");
	}
}
