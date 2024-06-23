/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keunykim <keunykim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 11:05:54 by keunykim          #+#    #+#             */
/*   Updated: 2024/06/23 20:49:14 by keunykim         ###   ########.fr       */
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

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strchr(s1, 0) - s1;
	len_s2 = ft_strchr(s2, 0) - s2;
	concat = (char *) malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!concat)
		return (NULL);
	ft_strlcpy(concat, s1, len_s1 + 1);
	ft_strlcat(concat, s2, len_s1 + len_s2 + 1);
	return (concat);
}

char	*ft_substr(char const *s, size_t start, size_t len)
{
	size_t	remain;
	size_t	size;
	char	*sub;

	if (!s)
		return (NULL);
	size = ft_strchr(s, 0) - s;
	if (size > start)
		remain = size - start;
	else
	{
		return (NULL);
	}
	if (len > remain)
		len = remain;
	sub = (char *) malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	ft_strlcpy(sub, s + start, len + 1);
	return (sub);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	begin_of_null;
	size_t	i;

	if (size == 0)
		return (ft_strchr(src, 0) - src);
	i = 0;
	while (dst[i] != '\0' && i < size)
		i++;
	begin_of_null = i;
	if (size <= begin_of_null)
		return (ft_strchr(src, 0) - src + size);
	i = 0;
	while (src[i] != '\0' && i < size - 1 - begin_of_null)
	{
		dst[begin_of_null + i] = src[i];
		i++;
	}
	dst[begin_of_null + i] = '\0';
	return (ft_strchr(src, 0) - src + begin_of_null);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	if (size == 0)
		return (ft_strchr(src, 0) - src);
	i = 0;
	while (src[i] != '\0' && i + 1 < size)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strchr(src, 0) - src);
}