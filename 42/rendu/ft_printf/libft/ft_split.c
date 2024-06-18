
#include "libft.h"

static char	*ft_tokenize(char const *s, char c, size_t index)
{
	char	*started;
	char	*copied;
	size_t	token_count;

	copied = (char *)s;
	token_count = 0;
	started = NULL;
	while (*copied != '\0')
	{
		if (token_count == index && *copied != c && started == NULL)
			started = copied;
		else if (*copied == c && (s - copied != 0))
		{
			if (*(copied - 1) != c && *(copied - 1) != '\0')
			{
				if (token_count == index && started != NULL)
					break ;
				else if (token_count < index)
					token_count++;
			}
		}
		copied++;
	}
	return (ft_substr(s, started - s, copied - started));
}

static size_t	ft_get_row_num(char const *s, char c)
{
	size_t	ret;
	size_t	index;
	size_t	checked_started;

	ret = 0;
	index = 0;
	checked_started = 0;
	while (s[index] != '\0')
	{
		if (index == 0 && s[index] != c)
			ret++;
		if (s[index] != c && checked_started == 0)
			checked_started = 1;
		if (index > 0 && s[index] != c && s[index - 1] == c && \
				s[index - 1] != '\0')
		{
			if (checked_started)
				ret++;
		}
		index++;
	}
	return (ret);
}

static void	ft_clear_split(char **ret, size_t row_num)
{
	size_t	index;

	index = 0;
	while (index < row_num)
		free(ret[index++]);
	free(ret);
}

char	**ft_split(char const *s, char c)
{
	char	**ret;
	char	*str;
	size_t	row_num;
	size_t	index;

	if (s == NULL)
		return (NULL);
	index = 0;
	row_num = ft_get_row_num(s, c);
	ret = (char **)ft_calloc((row_num + 1), sizeof(char *));
	if (ret == NULL)
		return (NULL);
	while (index < row_num)
	{
		str = ft_tokenize(s, c, index);
		if (str == NULL)
		{
			ft_clear_split(ret, row_num);
			return (NULL);
		}
		ret[index++] = str;
	}
	return (ret);
}
