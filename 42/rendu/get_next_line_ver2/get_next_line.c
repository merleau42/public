/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keunykim <keunykim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 11:05:58 by keunykim          #+#    #+#             */
/*   Updated: 2024/06/23 14:26:29 by keunykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_read_fd(int fd, char *repo)
{
	size_t		repo_size;
	ssize_t		response;
	char		*buff;

	if (repo == NULL)
	{
		repo = (char *)malloc(((size_t)BUFFER_SIZE + 1) * sizeof(char));
		*repo = '\0';
	}
	repo_size = ft_strlen(repo);
	response = 1;
	buff = (char *)malloc(((size_t)BUFFER_SIZE + 1) * sizeof(char));
	while (repo && response > 0)
	{
		response = read(fd, buff, BUFFER_SIZE);
		if (response > 0)
		{
			buff[response] = '\0';
			repo = ft_strjoin(repo, buff, repo_size, response);
			repo_size += BUFFER_SIZE;
			if (ft_strchr(buff, '\n') != NULL)
				break ;
		}
	}
	free(buff);
	return (1);
}

char	*ft_strnright(char *repo, size_t line_size)
{
	char	*left_repo;
	size_t	left_size;
	size_t	repo_size;
	size_t	index;

	repo_size = ft_strlen(repo);
	left_size = repo_size - line_size;
	if (repo == NULL || left_size == 0)
		return (NULL);
	left_repo = (char *)malloc((left_size + 1) * sizeof(char));
	if (!left_repo)
		return (NULL);
	index = 0;
	while (index + line_size < repo_size)
	{
		left_repo[index] = repo[index + line_size];
		index ++;
	}
	left_repo[index] = '\0';
	return (left_repo);
}
char	*get_next_line(int fd)
{
	static char	*repo;
	char		*tmp;
	char		*one_line;
	size_t		len;

	if (fd < 0 || BUFFER_SIZE <= 0 || (ft_read_fd(fd, repo) && !repo))
		return (NULL);
	if (strchr(repo, '\n'))
		len = strchr(repo, '\n') - repo + 1;
	else
		len = strchr(repo, '\0');
	one_line = ft_substr(repo, 0, len); //snd(repo, len)
	tmp = ft_strnright(repo, len);
	free(repo);
	repo = NULL;
	if (tmp != NULL)
		repo = tmp;
	return (one_line);
}