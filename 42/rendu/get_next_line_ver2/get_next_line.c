/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keunykim <keunykim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 11:05:58 by keunykim          #+#    #+#             */
/*   Updated: 2024/06/23 14:53:33 by keunykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_read_fd(int fd, char *storage)
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
	return (1);
}
// 기존 저장고에서 나머지 구하기
char	*ft_strnright(char *storage, size_t line_size)
{
	char	*left_storage;
	size_t	left_size;
	size_t	storage_size;
	size_t	index;

	storage_size = ft_strlen(storage);
	left_size = storage_size - line_size;
	if (storage == NULL || left_size == 0)
		return (NULL);
	left_storage = (char *)malloc((left_size + 1) * sizeof(char));
	if (!left_storage)
		return (NULL);
	index = 0;
	while (index + line_size < storage_size)
	{
		left_storage[index] = storage[index + line_size];
		index ++;
	}
	left_storage[index] = '\0';
	return (left_storage);
}
char	*get_next_line(int fd)
{
	static char	*storage;
	char		*tmp;
	char		*one_line;
	size_t		len;

	if (fd < 0 || BUFFER_SIZE <= 0 || (ft_read_fd(fd, storage) && !storage))
		return (NULL);
	if (strchr(storage, '\n'))
		len = strchr(storage, '\n') - storage + 1;
	else
		len = strchr(storage, '\0');
	one_line = ft_substr(storage, 0, len); //snd(storage, len)
	tmp = ft_strnright(storage, len);
	free(storage);
	storage = NULL;
	if (tmp != NULL)
		storage = tmp;
	return (one_line);
}