/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keunykim <keunykim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 11:05:58 by keunykim          #+#    #+#             */
/*   Updated: 2024/06/23 12:04:26 by keunykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_read_fd(int fd, char **repo)
{
	size_t		repo_size;
	ssize_t		response;
	char		*buff;

	response = 1;
	if (*repo == NULL)
	{
		*repo = (char *)malloc(((size_t)BUFFER_SIZE + 1) * sizeof(char));
		**repo = '\0';
	}
	repo_size = ft_strlen(*repo);
	buff = (char *)malloc(((size_t)BUFFER_SIZE + 1) * sizeof(char));
	while (*repo && response > 0)
	{
		response = read(fd, buff, BUFFER_SIZE);
		if (response > 0)
		{
			buff[response] = '\0';
			*repo = ft_strjoin(repo, buff, repo_size, response);
			repo_size += BUFFER_SIZE;
			if (ft_strchr(buff, '\n') != NULL)
				break ;
		}
	}
	free(buff);
	return (1);
}

char	*get_next_line(int fd)
{
	static char	*repo;
	char		*left_repo;
	char		*submit;
	size_t		index;

	if (fd < 0 || BUFFER_SIZE <= 0 || (ft_read_fd(fd, &repo) && !repo))
		return (NULL);


	index = 0;
	while (1)
	{
		if (repo[index] == '\n')
		{
			index ++;
			break ;
		}
		if (repo[index] == '\0')
			break ;
		index ++;
	}
	submit = ft_strndup(repo, index);




	left_repo = ft_strnright(repo, ft_strlen(repo), ft_strlen(submit));
	free(repo);
	repo = NULL;
	if (left_repo != NULL)
		repo = left_repo;
	return (submit);
}