/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keunykim <keunykim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 23:46:43 by keunykim          #+#    #+#             */
/*   Updated: 2024/03/13 21:37:23 by keunykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*bytes_d;
	unsigned char	*bytes_s;

	if (!dest && !src && n > 0)
		return (NULL);
	bytes_d = (unsigned char *) dest;
	bytes_s = (unsigned char *) src;
	i = 0;
	while (i < n)
	{
		bytes_d[i] = bytes_s[i];
		i++;
	}
	return (dest);
}
