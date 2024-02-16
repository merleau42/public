/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keunykim <keunykim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:16:22 by keunykim          #+#    #+#             */
/*   Updated: 2023/12/18 17:16:56 by keunykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_non_printable(char *str)
{
	unsigned char	bf;
	char			*hex;
	int				i;

	hex = "0123456789abcdef";
	i = 0;
	while (str[i] != '\0')
	{
		bf = (unsigned char)str[i];
		if (32 <= bf && bf <= 126)
			write(1, &bf, 1);
		else
		{
			write(1, "\\", 1);
			write(1, &hex[bf / 16], 1);
			write(1, &hex[bf % 16], 1);
		}
		i++;
	}
}
