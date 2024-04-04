/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keunykim <keunykim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 23:46:50 by keunykim          #+#    #+#             */
/*   Updated: 2024/03/13 21:37:42 by keunykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
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
		if (dest <= src)
			bytes_d[i] = bytes_s[i];
		else
			bytes_d[n - i - 1] = bytes_s[n - i - 1];
		i++;
	}
	return (dest);
}
