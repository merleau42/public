

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

/* get_next_line.c */
char	*get_next_line(int fd);
void	ft_read_fd(int fd, char **repo);
char	*ft_get_line(char *repo);
void	ft_remove_line(char **repo, char *line);

/* get_next_line_utils.c */
size_t	ft_strlen(char *s);
char	*ft_strchr(char *s, int c);
char	*ft_strndup(char *repo, size_t size);
char	*ft_strnright(char *repo, size_t repo_size, size_t line_size);
char	*ft_strjoin(char **repo, char *buf, size_t repo_size, size_t buf_size);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif /* BUFFER_SIZE */

#endif /* GET_NEXT_LINE_H */
