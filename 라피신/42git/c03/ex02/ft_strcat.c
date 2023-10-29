/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keunkim <keunkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 01:00:02 by keunkim           #+#    #+#             */
/*   Updated: 2023/08/11 01:00:33 by keunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	begin_of_null;

	i = 0;
	while (dest[i] != '\0')
		i++;
	begin_of_null = i;
	i = 0;
	while (src[i] != '\0')
	{
		dest[begin_of_null + i] = src[i];
		i++;
	}
	dest[begin_of_null + i] = '\0';
	return (dest);
}
