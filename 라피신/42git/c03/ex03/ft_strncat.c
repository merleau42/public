/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keunkim <keunkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 01:01:01 by keunkim           #+#    #+#             */
/*   Updated: 2023/08/11 01:01:11 by keunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	int	i;
	int	begin_of_null;

	i = 0;
	while (dest[i] != '\0')
		i++;
	begin_of_null = i;
	i = 0;
	while (nb && src[i] != '\0')
	{
		dest[begin_of_null + i] = src[i];
		i++;
		nb--;
	}
	dest[begin_of_null + i] = '\0';
	return (dest);
}
