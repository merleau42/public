/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keunykim <keunykim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:32:12 by keunykim          #+#    #+#             */
/*   Updated: 2024/02/22 21:45:00 by keunykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	i;
	int	pow;

	i = 1;
	while (0 <= nb && i <= 46340)
	{
		pow = i * i;
		if (pow == nb)
			return (i);
		else if (pow > nb)
			break ;
		else
			i++;
	}
	return (0);
}

// #include <stdio.h>
// int main(void)
// {
// 	printf("sqrt(0) == %d\n", ft_sqrt(0));
// 	for (int i=-1000; i <= 2147483647; i++)
// 		if (ft_sqrt(i) != 0)
// 			printf("sqrt(%d) == %d\n", i, ft_sqrt(i));
// }
