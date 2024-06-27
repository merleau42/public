/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keunykim <keunykim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 11:05:58 by keunykim          #+#    #+#             */
/*   Updated: 2024/06/24 16:52:34 by keunykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*take_off(char **strg)
{
	char		*leftovers;
	char		*piece;
	size_t		len;

	if (ft_strchr(*strg, '\n'))
		len = ft_strchr(*strg, '\n') - *strg + 1;
	else
		len = ft_strchr(*strg, '\0') - *strg;
	piece = ft_substr(*strg, 0, len);
	leftovers = ft_substr(*strg, len, ft_strchr(*strg, '\0') - *strg - len);
	free(*strg);
	*strg = leftovers;
	return (piece);
}

char	*get_next_line(int fd)
{
	static char	*storage;
	ssize_t		shovel;
	char		*cart;
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (storage == NULL)
		storage = ft_strjoin("", "");
	cart = (char *) malloc(((size_t)BUFFER_SIZE + 1) * sizeof (char));
	shovel = read(fd, cart, BUFFER_SIZE);
	while (shovel > 0)
	{
		cart[shovel] = '\0';
		tmp = ft_strjoin(storage, cart);
		free(storage);
		storage = tmp;
		if (ft_strchr(cart, '\n'))
			break ;
		shovel = read(fd, cart, BUFFER_SIZE);
	}
	free(cart);
	if (shovel == -1)
		return (NULL);
	return (take_off(&storage));
}
