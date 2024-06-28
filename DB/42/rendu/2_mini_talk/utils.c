/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keunykim <keunykim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 23:42:16 by keunykim          #+#    #+#             */
/*   Updated: 2024/06/29 00:04:25 by keunykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

size_t	ft_strlen(const char *s)
{
	const char	*rewind;

	rewind = s;
	while (*s != '\0')
		s++;
	return (s - rewind);
}


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

