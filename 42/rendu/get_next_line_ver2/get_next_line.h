/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keunykim <keunykim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 11:06:04 by keunykim          #+#    #+#             */
/*   Updated: 2024/06/23 14:29:55 by keunykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
void	ft_read_fd(int fd, char *storage);

size_t	ft_strlen(char *s);
char	*ft_strchr(char *s, int c);
// char	*ft_strndup(char *storage, size_t size);

// s[start + 0] 부터 s[start + len - 1] 까지, 총 len 바이트의 부분 문자열 추출
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strnright(char *storage, size_t storage_size, size_t line_size);
char	*ft_strjoin(char *storage, char *buf, size_t storage_size, size_t buf_size);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif /* BUFFER_SIZE */

#endif /* GET_NEXT_LINE_H */
