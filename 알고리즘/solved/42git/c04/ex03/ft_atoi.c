/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keunkim <keunkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 04:50:06 by keunkim           #+#    #+#             */
/*   Updated: 2023/08/11 04:50:51 by keunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	i;
	int	res;
	int	sign;

	i = 0;
	res = -1;
	sign = 1;
	while (str[i] != '\0')
	{
		if ('0' <= str[i] && str[i] <= '9')
			res = 10 * res * (res != -1) + str[i] - '0';
		else if (res == -1 && str[i] == '-')
			sign = -sign;
		else if (res != -1)
			break ;
		if (str[i] == '+' || str[i] == '-')
			if (str[i + 1] != '+' && str[i + 1] != '-')
				if (!('0' <= str[i + 1] && str[i + 1] <= '9'))
					return (0);
		i++;
	}
	return (res * sign * (res != -1));
}
