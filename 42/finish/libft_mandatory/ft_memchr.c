/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keunykim <keunykim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 23:46:29 by keunykim          #+#    #+#             */
/*   Updated: 2024/03/16 23:34:32 by keunykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*bytes;

	bytes = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		if (bytes[i] == (unsigned char) c)
			return ((void *)bytes + i);
		i++;
	}
	return (NULL);
}
