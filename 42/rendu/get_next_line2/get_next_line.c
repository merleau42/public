

#include "get_next_line.h"

void	ft_read_fd(int fd, char **repo)
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
}

char	*ft_get_line(char *repo)
{
	char	*line;
	size_t	index;

	index = 0;
	while (1)
	{
		if (repo[index] == '\n')
		{
			index ++;
			break ;
		}
		if (repo[index] == '\0')
		{
			break ;
		}
		index ++;
	}
	line = ft_strndup(repo, index);
	return (line);
}

void	ft_remove_line(char **repo, char *line)
{
	char	*left_repo;
	size_t	repo_size;
	size_t	line_size;

	repo_size = ft_strlen(*repo);
	line_size = ft_strlen(line);
	left_repo = ft_strnright(*repo, repo_size, line_size);
	free(*repo);
	*repo = NULL;
	if (left_repo != NULL)
	{
		*repo = left_repo;
	}
}

char	*get_next_line(int fd)
{
	static char	*repo;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	ft_read_fd(fd, &repo);
	if (repo == NULL)
	{
		return (NULL);
	}
	line = ft_get_line(repo);
	ft_remove_line(&repo, line);
	return (line);
}
