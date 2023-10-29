/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keunkim <keunkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 12:55:32 by keunkim           #+#    #+#             */
/*   Updated: 2023/08/06 15:41:12 by keunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	int				over;

	if (!size)
		return (ft_strlen(src));
	over = 0;
	i = 0;
	while (i < size - 1)
	{
		if (over == 0 && src[i] == '\0')
			over = 1;
		if (over)
		{
			dest[i] = '\0';
			break ;
		}
		else
			dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (ft_strlen(src));
}
