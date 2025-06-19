/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keunykim <keunykim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 02:07:53 by keunykim          #+#    #+#             */
/*   Updated: 2023/12/19 04:04:06 by keunykim         ###   ########.fr       */
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

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	begin_of_null;

	i = 0;
	while (dest[i] != '\0')
		i++;
	begin_of_null = i;
	if (size <= begin_of_null)
		return (ft_strlen(src) + size);
	i = 0;
	while (begin_of_null + i + 1 < size && src[i] != '\0')
	{
		dest[begin_of_null + i] = src[i];
		i++;
	}
	dest[begin_of_null + i] = '\0';
	return (ft_strlen(src) + begin_of_null);
}
