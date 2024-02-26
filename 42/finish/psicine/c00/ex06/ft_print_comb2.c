/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keunykim <keunykim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 01:44:55 by keunykim          #+#    #+#             */
/*   Updated: 2023/12/18 02:23:03 by keunykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb2(void)
{
	int		dec[3];
	char	temp[2];

	dec[1] = 0;
	while (dec[1] <= 98)
	{
		dec[2] = dec[1] + 1;
		while (dec[2] <= 99)
		{
			temp[0] = dec[1] / 10 + '0';
			temp[1] = dec[1] % 10 + '0';
			write(1, temp, 2);
			write(1, " ", 1);
			temp[0] = dec[2] / 10 + '0';
			temp[1] = dec[2] % 10 + '0';
			write(1, temp, 2);
			if (dec[1] + dec[2] < 98 + 99)
				write(1, ", ", 2);
			dec[2]++;
		}
		dec[1]++;
	}
}
