/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keunykim <keunykim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 07:01:00 by keunykim          #+#    #+#             */
/*   Updated: 2023/12/22 07:01:29 by keunykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	ret;

	if (nb == 0 || nb == 1)
		return (1);
	if (nb < 0)
		return (0);
	ret = 1;
	while (nb)
	{
		ret = ret * nb;
		nb--;
	}
	return (ret);
}
