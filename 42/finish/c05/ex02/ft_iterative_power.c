/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keunykim <keunykim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 07:00:11 by keunykim          #+#    #+#             */
/*   Updated: 2023/12/22 07:00:14 by keunykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	ret;

	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	ret = 1;
	while (power)
	{
		ret = ret * nb;
		power--;
	}
	return (ret);
}
