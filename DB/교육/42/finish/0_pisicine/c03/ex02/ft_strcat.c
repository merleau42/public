/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keunykim <keunykim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 02:09:18 by keunykim          #+#    #+#             */
/*   Updated: 2023/12/19 02:09:55 by keunykim         ###   ########.fr       */
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
