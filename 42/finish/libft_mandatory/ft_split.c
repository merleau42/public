/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keunykim <keunykim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 23:49:00 by keunykim          #+#    #+#             */
/*   Updated: 2024/04/04 20:22:35 by keunykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_word_count(char const *s, char c)
{
	size_t	words;

	words = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			words++;
		while (*s && *s != c)
			s++;
	}
	return (words);
}

static	char	**free_all(char **frame, size_t allocated)
{
	size_t	i;

	i = 0;
	while (i < allocated)
		free(frame[i++]);
	free (frame);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char		**frame;
	size_t		words;
	char const	*word_start;
	size_t		i;

	if (!s)
		return (NULL);
	words = ft_word_count(s, c);
	frame = (char **) malloc(sizeof(char *) * (words + 1));
	i = 0;
	while (frame && i < words)
	{
		while (*s == c)
			s++;
		word_start = s;
		while (*s && *s != c)
			s++;
		frame[i] = ft_substr(word_start, 0, s - word_start);
		if (!frame[i])
			return (free_all(frame, i));
		i++;
	}
	if (frame)
		frame[i] = (char *) 0;
	return (frame);
}

#include <stdio.h>
int	main()
{
	char *a[3];

	a = ft_split("   ab  cd  ef   ", '');
	printf("%s", a[0]);
	printf("%s", a[1]);
	printf("%s", a[2]);
	printf("%s", a[3]);
}