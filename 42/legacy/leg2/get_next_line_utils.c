#include "get_next_line.h"

char	*ft_strchr(char *s, int c)
{
	size_t	index;
	size_t	size;
	char	*ret;

	ret = NULL;
	size = ft_strlen(s);
	index = 0;
	while (index <= size)
	{
		if (s[index] == ((char)c))
		{
			ret = &((char *)s)[index];
			break ;
		}
		index++;
	}
	return (ret);
}

size_t	ft_strlen(char *s)
{
	char	*copied;

	if (s == NULL)
		return (0);
	copied = s;
	while (*copied != '\0')
	{
		copied++;
	}
	return (copied - s);
}

char	*ft_strjoin(char **repo, char *buf, size_t repo_size, size_t buf_size)
{
	char	*ret;
	size_t	index;

	index = 0;
	if (*repo == NULL || buf == NULL)
		return (NULL);
	ret = (char *)malloc((repo_size + buf_size + 1) * sizeof(char));
	if (ret == NULL)
		return (NULL);
	while (index < repo_size + buf_size)
	{
		if (index < repo_size)
			ret[index] = (*repo)[index];
		else
			ret[index] = buf[index - repo_size];
		index++;
	}
	ret[index] = '\0';
	free(*repo);
	return (ret);
}

char	*ft_strnright(char *repo, size_t repo_size, size_t line_size)
{
	char	*left_repo;
	size_t	left_size;
	size_t	index;

	left_size = repo_size - line_size;
	if (repo == NULL || left_size == 0)
		return (NULL);
	left_repo = (char *)malloc((left_size + 1) * sizeof(char));
	if (left_repo == NULL)
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

char	*ft_strndup(char *repo, size_t size)
{
	size_t		index;
	char		*line;

	index = 0;
	if (size == 0)
		return (NULL);
	line = (char *)malloc((size + 1) * sizeof(char));
	if (line == NULL)
		return (NULL);
	while (index < size)
	{
		line[index] = repo[index];
		index++;
	}
	line[index] = '\0';
	return (line);
}
