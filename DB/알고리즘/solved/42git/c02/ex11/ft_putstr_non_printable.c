/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keunkim <keunkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 12:56:24 by keunkim           #+#    #+#             */
/*   Updated: 2023/08/10 17:19:25 by keunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_non_printable(char *str)
{
	unsigned char	buf;
	char			*hex;
	int				i;

	hex = "0123456789abcdef";
	i = 0;
	while (str[i] != '\0')
	{
		buf = str[i];
		if (32 <= buf && buf <= 126)
			write(1, &buf, 1);
		else
		{
			write(1, "\\", 1);
			write(1, &hex[buf / 16], 1);
			write(1, &hex[buf % 16], 1);
		}
		i++;
	}
}
