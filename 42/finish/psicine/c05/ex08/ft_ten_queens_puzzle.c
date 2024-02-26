/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keunykim <keunykim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 06:50:10 by keunykim          #+#    #+#             */
/*   Updated: 2023/12/22 08:00:25 by keunykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb)
{
	char	conv[10];
	char	start;
	int		i;

	if (nb == -2147483648)
		write(1, "-2147483648", 11);
	else
	{
		if (nb < 0)
		{
			write(1, "-", 1);
			nb = -nb;
		}
		i = 10;
		start = 9;
		while (i--)
		{
			conv[i] = nb % 10 + '0';
			nb = nb / 10;
			if (conv[i] != '0')
				start = i;
		}
		write(1, conv + start, 10 - start);
	}
}

int	is_valid_n_queen(int *dec)
{
	int	i;
	int	j;

	i = 0;
	while (i < 10)
	{
		j = i + 1;
		while (j < 10)
		{
			if (dec[i] == dec[j]
				|| (dec[i] - dec[j] == i - j) || (dec[i] - dec[j] == j - i))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	kth_while(int k, int *dec, int *exist, int *sols)
{
	int	i;

	dec[k] = 0;
	while (dec[k] <= 9)
	{
		if (exist[dec[k]] == 0)
			exist[dec[k]] = 1;
		else
		{
			dec[k]++;
			continue ;
		}
		if (k != 9)
			kth_while(k + 1, dec, exist, sols);
		if (k == 9 && is_valid_n_queen(dec))
		{
			i = 0;
			while (i <= 9)
				ft_putnbr(dec[i++]);
			write(1, "\n", 1);
			(*sols)++;
		}
		exist[dec[k]] = 0;
		dec[k]++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	dec[10];
	int	exist[10];
	int	i;
	int	sols;

	i = 0;
	sols = 0;
	while (i < 10)
	{
		dec[i] = 0;
		exist[i] = 0;
		i++;
	}
	kth_while(0, dec, exist, &sols);
	return (sols);
}
