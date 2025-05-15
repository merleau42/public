/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keunykim <keunykim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:14:46 by keunykim          #+#    #+#             */
/*   Updated: 2024/02/22 22:51:17 by keunykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	i;
	int	res;

	if (nb < 0 || nb > 12)
		return (0);
	if (nb <= 1)
		return (1);
	res = 1;
	i = 1;
	while (i <= nb)
		res = res * i++;
	return (res);
}

// #include <stdio.h>
// int main(void)
// {
// 	int tc[] = {-2,-1,0,1,2,3,4,5,6,7,8,9,10,11,12,13,14};
// 	for (int i=0; i<(int)sizeof(tc)/4; i++)
// 		printf("%d! == %d\n", tc[i], ft_iterative_factorial(tc[i]));
// }
