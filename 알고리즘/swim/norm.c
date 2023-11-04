/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keunkim <keunkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 03:32:54 by keunkim           #+#    #+#             */
/*   Updated: 2023/08/11 03:40:12 by keunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	res;
	int	sign;
	int	nary;

	i = 0;
	res = -1;
	sign = 1;
	nary = vaild_base(base);
	if (nary < 2)
		return (0);
	while (str[i] != '\0')
	{
		if (is_custom_number(str[i], base) < ft_strlen(base))
			res = nary * res * (res != -1) + is_custom_number(str[i], base);
		else if (res == -1 && str[i] == '-')
			sign = -sign;
		else if (res != -1)
			break ;
		if ((str[i] == 43 | str[i] == 45) & str[i + 1] != 43 & str[i + 1] != 45)
			if (!(is_custom_number(str[i + 1], base) < ft_strlen(base)))
				return (0);
		i++;
	}
	return (res * sign * (res != -1));
}
