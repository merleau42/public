/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keunykim <keunykim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 18:21:27 by keunykim          #+#    #+#             */
/*   Updated: 2024/02/23 18:01:45 by keunykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	*tab;

	if (min >= max)
		return ((int *)0);
	tab = malloc(sizeof (int) * (max - min));
	i = 0;
	while (i < max - min)
	{
		tab[i] = min + i;
		i++;
	}
	return (tab);
}

// #include <stdio.h>
// int main(void)
// {
// 	int *tab;
// 	tab = ft_range(-13,13);
// 	for (int i=0; i<26; i++)
// 		printf("%d ", tab[i]);
// }
