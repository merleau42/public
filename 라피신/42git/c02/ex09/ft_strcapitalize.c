/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keunkim <keunkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 12:53:57 by keunkim           #+#    #+#             */
/*   Updated: 2023/08/10 16:37:18 by keunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strupcase2(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ('a' <= str[i] && str[i] <= 'z')
			str[i] = str[i] - 32;
		i++;
	}
	return (str);
}

char	*ft_strlowcase2(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ('A' <= str[i] && str[i] <= 'Z')
			str[i] = str[i] + 32;
		i++;
	}
	return (str);
}

int	ft_is_word(char c)
{
	int	d;

	d = ('A' <= c & c <= 'Z') | ('a' <= c & c <= 'z') | ('0' <= c & c <= '9');
	return (d);
}

char	*ft_strcapitalize(char *str)
{
	int		i;
	char	*now;

	i = 0;
	while (str[i] != '\0')
	{
		now = &str[i];
		if (ft_is_word(*now))
		{
			if (i == 0)
				ft_strupcase2(now);
			else if (!ft_is_word(str[i - 1]))
				ft_strupcase2(now);
			else if (ft_is_word(str[i - 1]))
				ft_strlowcase2(now);
		}
		i++;
	}
	return (str);
}
