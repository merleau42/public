/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils___.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keunykim <keunykim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 11:05:54 by keunykim          #+#    #+#             */
/*   Updated: 2024/06/23 11:35:03 by keunykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// 문자열에 특정한 문자가 포함되는지 검사하고 위치를 반환. 없으면 NULL 반환.
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

// 문자열의 길이 출력 (널문자를 제외한 바이트수)
size_t	ft_strlen(const char *s)
{
	const char	*rewind;

	if (s == NULL)
		return (0);
	rewind = s;
	while (*s != '\0')
		s++;
	return (s - rewind);
}

// 
char	*ft_strjoin(char **repo, char *buf, size_t repo_size, size_t buf_size)
{
	char	*concat;
	size_t	index;

	if (*repo == NULL || buf == NULL)
		return (NULL);
	concat = (char *) malloc(sizeof(char) * (repo_size + buf_size + 1));
	if (!concat)
		return (NULL);
	index = 0;
	while (index < repo_size + buf_size)
	{
		if (index < repo_size)
			concat[index] = (*repo)[index];
		else
			concat[index] = buf[index - repo_size];
		index++;
	}
	concat[index] = '\0';
	free(*repo);
	return (concat);
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
// 문자열에서 len개의 문자만 복제하여 새로운 문자열을 반환함 (dragon,4 ---> drag)
char	*ft_strndup(const char *s, size_t len)
{
	size_t		index;
	char		*dest;

	dest = (char *) malloc(sizeof (char) * (len + 1));
	if (!dest)
		return (NULL);
	index = 0;
	while (index < len)
	{
		dest[index] = s[index];
		index++;
	}
	dest[index] = '\0';
	return (dest);
}