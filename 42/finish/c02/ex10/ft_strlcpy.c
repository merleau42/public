/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keunykim <keunykim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:17:39 by keunykim          #+#    #+#             */
/*   Updated: 2023/12/18 18:06:22 by keunykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	n;
	unsigned int	i;

	n = size;
	if (n == 0)
		return (ft_strlen2(src));
	i = 0;
	while (src[i] != '\0' && i + 1 < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (ft_strlen2(src));
}
