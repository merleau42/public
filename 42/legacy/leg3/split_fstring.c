/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_fstring.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dae-lee <dae-lee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 20:13:42 by dae-lee           #+#    #+#             */
/*   Updated: 2024/03/04 21:36:46 by dae-lee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_next_format_idx(char const *str, char **format_strs)
{
	int	i;
	int	format_type;

	i = 0;
	while (str[i])
	{
		format_type = 0;
		while (format_type != F_NONE)
		{
			if (ft_strncmp(str + i, format_strs[format_type++], 2) == 0)
				return (i);
		}
		i++;
	}
	return (-1);
}

static char	*ft_sub_strdup(char **split_strs, const char *s, size_t str_len)
{
	*split_strs = (char *)malloc(sizeof(char) * (str_len + 1));
	if (*split_strs == NULL)
		return (NULL);
	ft_strlcpy(*split_strs, s, str_len + 1);
	return (*split_strs);
}

static void	*fill_split_strs(char **split_strs, char const *str,
					int str_length, char **format_sep)
{
	int	idx;
	int	next_fm_i;

	idx = 0;
	next_fm_i = get_next_format_idx(str + idx, format_sep);
	while (next_fm_i != -1)
	{
		if (next_fm_i != 0)
		{
			if (!ft_sub_strdup(split_strs++, str + idx, next_fm_i))
				return (NULL);
		}
		if (!ft_sub_strdup(split_strs++, str + idx + next_fm_i, 2))
			return (NULL);
		idx = idx + (next_fm_i + 2);
		next_fm_i = get_next_format_idx(str + idx, format_sep);
	}
	if (idx < str_length)
	{
		if (!ft_sub_strdup(split_strs++, str + idx, (str_length - idx)))
			return (NULL);
	}
	return (split_strs);
}

static int	get_split_size(char const *str, int str_length, char **format_sep)
{
	int	split_size;
	int	idx;
	int	next_fm_i;

	if (str_length == 0)
		return (0);
	split_size = 0;
	idx = 0;
	next_fm_i = get_next_format_idx(str + idx, format_sep);
	while (next_fm_i != -1)
	{
		if (next_fm_i != 0)
			split_size++;
		split_size++;
		idx = idx + (next_fm_i + 2);
		next_fm_i = get_next_format_idx(str + idx, format_sep);
	}
	if (idx < str_length)
		split_size++;
	return (split_size);
}

/*
	Returns an array of strings separated by format_sep from the target string.
	At this time, format_sep is also added as one divided string.
*/
char	**split_fstring(char const *str, char **format_sep)
{
	char	**split_strs;
	int		split_size;
	int		str_length;
	char	**temp;

	if (str == NULL)
		return (NULL);
	str_length = 0;
	while (str[str_length])
		str_length++;
	split_size = get_split_size(str, str_length, format_sep);
	split_strs = malloc(sizeof(char *) * (split_size + 1));
	if (split_strs == NULL)
		return (NULL);
	if ((split_size > 0)
		&& (NULL == fill_split_strs(split_strs, str, str_length, format_sep)))
	{
		temp = split_strs;
		while (*split_strs != NULL)
			free(*(split_strs++));
		free(temp);
		return (NULL);
	}
	split_strs[split_size] = NULL;
	return (split_strs);
}
