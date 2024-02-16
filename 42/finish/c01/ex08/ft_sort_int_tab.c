/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keunykim <keunykim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:51:08 by keunykim          #+#    #+#             */
/*   Updated: 2023/12/18 18:28:54 by keunykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap2(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	sorted;

	sorted = 0;
	while (sorted == 0)
	{
		sorted = 1;
		i = 0;
		while (i < size - 1)
		{
			if (tab[i] > tab[i + 1])
			{
				ft_swap2(&tab[i], &tab[i + 1]);
				sorted = 0;
			}
			i++;
		}
	}
}
