/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keunykim <keunykim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 23:49:09 by keunykim          #+#    #+#             */
/*   Updated: 2024/03/13 18:27:13 by keunykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*map;
	char	*rewind;

	if (!s || !f)
		return (NULL);
	map = ft_strdup(s);
	if (!map)
		return (NULL);
	rewind = map;
	while (*map)
	{
		*map = (*f)(map - rewind, *map);
		map++;
	}
	return (rewind);
}
