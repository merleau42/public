/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keunkim <keunkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 11:15:50 by keunkim           #+#    #+#             */
/*   Updated: 2023/08/05 14:54:56 by keunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_convert_and_print(int n)
{
	char	conv[2];

	conv[0] = n / 10 + '0';
	conv[1] = n % 10 + '0';
	write(1, conv, 2);
}

void	ft_print_comb2(void)
{
	int	dec[3];

	dec[0] = -1;
	dec[1] = dec[0] + 1;
	while (dec[1] <= 98)
	{
		dec[2] = dec[1] + 1;
		while (dec[2] <= 99)
		{
			ft_convert_and_print(dec[1]);
			write(1, " ", 1);
			ft_convert_and_print(dec[2]);
			if (dec[1] + dec[2] < 98 + 99)
				write(1, ", ", 2);
			dec[2]++;
		}
		dec[1]++;
	}
}
