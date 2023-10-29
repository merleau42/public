/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keunkim <keunkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 01:01:48 by keunkim           #+#    #+#             */
/*   Updated: 2023/08/11 01:05:53 by keunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
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
	while (i < size - 1 - begin_of_null && src[i] != '\0')
	{
		dest[begin_of_null + i] = src[i];
		i++;
	}
	dest[begin_of_null + i] = '\0';
	return (ft_strlen(src) + begin_of_null);
}
