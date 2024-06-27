/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keunykim <keunykim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 23:49:47 by keunykim          #+#    #+#             */
/*   Updated: 2024/03/19 20:44:54 by keunykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	char	*rewind;

	if (!s || !f)
		return ;
	rewind = s;
	while (*s)
	{
		(*f)(s - rewind, s);
		s++;
	}
}
