/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keunykim <keunykim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 23:47:15 by keunykim          #+#    #+#             */
/*   Updated: 2024/03/11 23:53:58 by keunykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*bytes_s1;
	unsigned char	*bytes_s2;

	bytes_s1 = (unsigned char *) s1;
	bytes_s2 = (unsigned char *) s2;
	i = 0;
	while (bytes_s1[i] != '\0' || bytes_s2[i] != '\0')
	{
		if (i >= n)
			return (0);
		if (bytes_s1[i] != bytes_s2[i])
			break ;
		i++;
	}
	return (bytes_s1[i] - bytes_s2[i]);
}
