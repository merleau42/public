#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <stdint.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

size_t			ft_strlen(const char *str);
char			*ft_itoa(int n);

#endif