
#include "libft.h"

static int	ft_check_included(char character, char const *set, size_t set_size)
{
	size_t	index;

	index = 0;
	while (index < set_size)
	{
		if (character == set[index])
			return (1);
		index ++;
	}
	return (0);
}

static size_t	ft_check_trimable_back(char const *s1, char const *set)
{
	size_t	s1_index;
	size_t	s1_size;
	size_t	set_size;

	s1_size = ft_strlen(s1);
	set_size = ft_strlen(set);
	s1_index = s1_size;
	while (s1_index > 0)
	{
		if (ft_check_included(s1[s1_index - 1], set, set_size))
			s1_index--;
		else
			break ;
	}
	return (s1_index);
}

static size_t	ft_check_trimable_front(char const *s1, char const *set)
{
	size_t	s1_index;
	size_t	s1_size;
	size_t	set_size;

	s1_index = 0;
	s1_size = ft_strlen(s1);
	set_size = ft_strlen(set);
	while (s1_index < s1_size)
	{
		if (ft_check_included(s1[s1_index], set, set_size))
			s1_index++;
		else
			break ;
	}
	return (s1_index);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ret;
	size_t	front_index;
	size_t	back_index;
	size_t	ret_index;
	int		size;

	if (s1 == NULL || set == NULL)
		return (NULL);
	ret_index = 0;
	front_index = ft_check_trimable_front(s1, set);
	back_index = ft_check_trimable_back(s1, set);
	size = back_index - front_index;
	if (size < 0)
		size *= (-1);
	ret = malloc((size + 1) * sizeof(char));
	if (ret == NULL)
		return (NULL);
	while (front_index < back_index)
		ret[ret_index++] = s1[front_index++];
	ret[ret_index] = '\0';
	return (ret);
}
