/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keunykim <keunykim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 11:05:58 by keunykim          #+#    #+#             */
/*   Updated: 2024/06/23 15:39:51 by keunykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_read_fd(int fd, char *storage)
{
	size_t		storage_size;
	ssize_t		response;
	char		*buff;

	if (storage == NULL)
	{
		storage = (char *)malloc(((size_t)BUFFER_SIZE + 1) * sizeof(char));
		*storage = '\0';
	}
	storage_size = ft_strlen(storage);
	response = 1;
	buff = (char *)malloc(((size_t)BUFFER_SIZE + 1) * sizeof(char));
	while (storage && response > 0)
	{
		response = read(fd, buff, BUFFER_SIZE);
		if (response > 0)
		{
			buff[response] = '\0';
			storage = ft_strjoin(storage, buff, storage_size, response);
			storage_size += BUFFER_SIZE;
			if (ft_strchr(buff, '\n') != NULL)
				break ;
		}
	}
	free(buff);
}

char	*ft_leftovers(char *storage, size_t piece_size)
{
	char	*leftovers;
	size_t	storage_size;
	size_t	leftovers_size;
	size_t	index;

	storage_size = ft_strlen(storage);
	leftovers_size = storage_size - piece_size;
	if (storage == NULL || leftovers_size == 0)
		return (NULL);
	leftovers = (char *) malloc((leftovers_size + 1) * sizeof(char));
	if (!leftovers)
		return (NULL);
	index = 0;
	while (piece_size + index < storage_size)
	{
		leftovers[index] = storage[piece_size + index];
		index ++;
	}
	leftovers[index] = '\0';
	return (leftovers);
}

char	*get_next_line(int fd)
{
	static char	*storage;
	char		*leftovers;
	char		*piece;
	size_t		len;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	ft_read_fd(fd, storage);
	if (!storage)
		return (NULL);
	if (strchr(storage, '\n'))
		len = strchr(storage, '\n') - storage + 1;
	else
		len = strchr(storage, '\0');
	piece = ft_substr(storage, 0, len);	// snd(storage, len)
	leftovers = ft_leftovers(storage, len);
	free(storage);
	// storage = NULL;
	// if (leftovers != NULL)
		storage = leftovers;
	return (piece);
}