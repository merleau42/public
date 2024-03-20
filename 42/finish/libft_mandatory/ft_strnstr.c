/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keunykim <keunykim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 23:47:33 by keunykim          #+#    #+#             */
/*   Updated: 2024/03/13 21:26:50 by keunykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	len_ltt;

	if (!big && !len)
		return (NULL);
	if (little[0] == '\0')
		return ((char *) big);
	len_ltt = ft_strlen(little);
	i = 0;
	while (big[i] != '\0' && i < len)
	{
		if (len - i < len_ltt)
			break ;
		if (big[i] == little[0])
			if (ft_strncmp(big + i, little, len_ltt) == 0)
				return ((char *) big + i);
		i++;
	}
	return (NULL);
}
