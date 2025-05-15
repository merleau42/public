/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keunykim <keunykim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 02:08:11 by keunykim          #+#    #+#             */
/*   Updated: 2023/12/19 05:43:47 by keunykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp2(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (i >= n)
			return (0);
		if (s1[i] != s2[i])
			break ;
		i++;
	}
	return (s1[i] - s2[i]);
}

int	ft_strlen2(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i;

	if (to_find[0] == '\0')
		return (str);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == to_find[0])
			if (ft_strncmp2(str + i, to_find, ft_strlen2(to_find)) == 0)
				return (str + i);
		i++;
	}
	return ((void *)0);
}
