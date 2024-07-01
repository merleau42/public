/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keunykim <keunykim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 11:05:58 by keunykim          #+#    #+#             */
/*   Updated: 2024/07/01 11:58:13 by keunykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return ((char *) s + i);
		i++;
	}
	if (c == '\0')
		return ((char *) s + i);
	else
		return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*concat;
	size_t	index;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strchr(s1, '\0') - s1;
	len_s2 = ft_strchr(s2, '\0') - s2;
	concat = (char *) malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!concat)
		return (NULL);
	index = 0;
	while (index < len_s1 + len_s2)
	{
		if (index < len_s1)
			concat[index] = s1[index];
		else
			concat[index] = s2[index - len_s1];
		index++;
	}
	concat[index] = '\0';
	return (concat);
}

char	*ft_substr(char const *s, size_t start, size_t len)
{
	size_t	remain;
	size_t	size;
	char	*sub;
	size_t	index;

	if (!s)
		return (NULL);
	size = ft_strchr(s, '\0') - s;
	if (size <= start)
		return (NULL);
	remain = size - start;
	if (len > remain)
		len = remain;
	sub = (char *) malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	index = 0;
	while (index < len)
	{
		sub[index] = s[start + index];
		index++;
	}
	sub[index] = '\0';
	return (sub);
}

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
		if (ft_strchr(storage, '\n'))
			break ;
		shovel = read(fd, cart, BUFFER_SIZE);
	}
	free(cart);
	if (shovel == -1)
		return (NULL);
	return (take_off(&storage));
}
