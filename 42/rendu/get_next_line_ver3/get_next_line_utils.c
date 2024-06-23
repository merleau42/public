/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keunykim <keunykim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 11:05:54 by keunykim          #+#    #+#             */
/*   Updated: 2024/06/23 16:28:46 by keunykim         ###   ########.fr       */
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
char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*concat;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	concat = (char *) malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!concat)
		return (NULL);
	ft_strlcpy(concat, s1, len_s1 + 1);
	ft_strlcat(concat, s2, len_s1 + len_s2 + 1);
	return (concat);
}

// s[start + 0] 부터 s[start + len - 1] 까지, 총 len 바이트의 부분 문자열 추출
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	remain;
	size_t	s_len;
	char	*sub;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (s_len > start)
		remain = s_len - start;
	else
	{
		start = 0;
		remain = 0;
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
		return (ft_strlen(src));
	i = 0;
	while (dst[i] != '\0' && i < size)
		i++;
	begin_of_null = i;
	if (size <= begin_of_null)
		return (ft_strlen(src) + size);
	i = 0;
	while (src[i] != '\0' && i < size - 1 - begin_of_null)
	{
		dst[begin_of_null + i] = src[i];
		i++;
	}
	dst[begin_of_null + i] = '\0';
	return (ft_strlen(src) + begin_of_null);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	if (size == 0)
		return (ft_strlen(src));
	i = 0;
	while (src[i] != '\0' && i + 1 < size)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}