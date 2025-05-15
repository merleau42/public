/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keunykim <keunykim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 02:08:57 by keunykim          #+#    #+#             */
/*   Updated: 2023/12/19 02:09:15 by keunykim         ###   ########.fr       */
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
