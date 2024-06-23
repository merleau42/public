/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keunykim <keunykim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 11:05:54 by keunykim          #+#    #+#             */
/*   Updated: 2024/06/23 15:27:25 by keunykim         ###   ########.fr       */
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
char	*ft_strjoin(char *storage, char *buf, size_t storage_size, size_t buf_size)
{
	char	*concat;
	size_t	index;

	if (storage == NULL || buf == NULL)
		return (NULL);
	concat = (char *) malloc(sizeof(char) * (storage_size + buf_size + 1));
	if (!concat)
		return (NULL);
	index = 0;
	while (index < storage_size + buf_size)
	{
		if (index < storage_size)
			concat[index] = storage[index];
		else
			concat[index] = buf[index - storage_size];
		index++;
	}
	concat[index] = '\0';
	free(storage);
	return (concat);
}

// 문자열에서 len개의 문자만 복제하여 새로운 문자열을 반환함 (dragon,4 ---> drag)
// char	*ft_strndup(const char *s, size_t len)
// {
// 	size_t		index;
// 	char		*dest;

// 	dest = (char *) malloc(sizeof (char) * (len + 1));
// 	if (!dest)
// 		return (NULL);
// 	index = 0;
// 	while (index < len)
// 	{
// 		dest[index] = s[index];
// 		index++;
// 	}
// 	dest[index] = '\0';
// 	return (dest);
// }

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