/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keunykim <keunykim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 23:47:24 by keunykim          #+#    #+#             */
/*   Updated: 2024/03/11 23:54:42 by keunykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*bytes_s1;
	unsigned char	*bytes_s2;

	bytes_s1 = (unsigned char *) s1;
	bytes_s2 = (unsigned char *) s2;
	i = 0;
	while (1)
	{
		if (i >= n)
			return (0);
		if (bytes_s1[i] != bytes_s2[i])
			break ;
		i++;
	}
	return (bytes_s1[i] - bytes_s2[i]);
}
