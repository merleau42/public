/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keunykim <keunykim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 23:47:53 by keunykim          #+#    #+#             */
/*   Updated: 2024/03/11 23:54:47 by keunykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	conv[11];
	int		start;
	int		i;
	int		sign;

	sign = (n < 0);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	else
	{
		i = 11;
		start = 10;
		while (i--)
		{
			conv[i] = (n * (1 - 2 * sign)) % 10 + '0';
			n = n / 10;
			if (conv[i] != '0')
				start = i;
		}
		conv[start - 1] = '-';
		return (ft_strdup(conv + start - sign));
	}	
}
