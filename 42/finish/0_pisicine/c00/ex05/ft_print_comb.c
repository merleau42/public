/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keunykim <keunykim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 01:44:52 by keunykim          #+#    #+#             */
/*   Updated: 2023/12/18 02:16:31 by keunykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb(void)
{
	char	dec[4];

	dec[0] = '0' - 1;
	dec[1] = dec[0] + 1;
	while (dec[1] <= '7')
	{
		dec[2] = dec[1] + 1;
		while (dec[2] <= '8')
		{
			dec[3] = dec[2] + 1;
			while (dec[3] <= '9')
			{
				write(1, dec + 1, 3);
				if (dec[1] + dec[2] + dec[3] < '7' + '8' + '9')
					write(1, ", ", 2);
				dec[3]++;
			}
			dec[2]++;
		}
		dec[1]++;
	}
}
