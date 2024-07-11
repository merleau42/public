/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keunykim <keunykim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 04:06:55 by keunykim          #+#    #+#             */
/*   Updated: 2024/07/06 04:08:04 by keunykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *nptr)
{
	int	res;
	int	sign;
	int	i;

	res = 0;
	sign = 1;
	i = 0;
	while ((9 <= nptr[i] && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
		sign = sign * (44 - nptr[i++]);
	if (nptr[i] == '-' || nptr[i] == '+')
		return (0);
	while ('0' <= nptr[i] && nptr[i] <= '9')
		res = 10 * res + (nptr[i++] - '0');
	return (res * sign);
}

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*bytes;
	size_t			i;

	bytes = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		bytes[i] = (unsigned char) c;
		i++;
	}
	return (s);
}
