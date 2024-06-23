/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keunykim <keunykim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 11:05:58 by keunykim          #+#    #+#             */
/*   Updated: 2024/06/23 16:22:14 by keunykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_read_fd(int fd, char *storage)
{
	ssize_t		shovel; // 파일은 '파여질' 이라는 뜻. that would be sholved.
	char		*buff;
	char		*tmp;

	if (storage == NULL)
	{
		storage = (char *) malloc(((size_t)BUFFER_SIZE + 1) * sizeof (char));
		*storage = '\0';
	}
	buff = (char *) malloc(((size_t)BUFFER_SIZE + 1) * sizeof (char));
	shovel = 1;
	while (storage && shovel > 0)
	{
		shovel = read(fd, buff, BUFFER_SIZE);
		if (shovel > 0)
		{
			buff[shovel] = '\0';
			tmp = ft_strjoin(storage, buff);
			free(storage);
			storage = tmp;
			if (ft_strchr(buff, '\n') != NULL)
				break ;
		}
	}
	free(buff);
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
	if (ft_strchr(storage, '\n'))
		len = ft_strchr(storage, '\n') - storage + 1;
	else
		len = fr_strlen(storage);
	piece = ft_substr(storage, 0, len);
	leftovers = ft_substr(storage, len, ft_strlen(storage));
	free(storage);
	storage = leftovers;
	return (piece);
}

int main()
{
	int		fd;
	char	*line;
	
	fd = open('sample', O_RDONLY);

	line = get_next_line(fd);
	printf("%s", line);
	line = get_next_line(fd);
	printf("%s", line);
	line = get_next_line(fd);
	printf("%s", line);

	close(fd);
}