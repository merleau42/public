/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keunykim <keunykim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:46:33 by keunykim          #+#    #+#             */
/*   Updated: 2024/02/22 21:45:32 by keunykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

// #include <unistd.h>
// void ft_putchar(char c)
// {
// 	write(1,&c,1);
// }

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

// int main(void)
// {
// 	ft_putstr("hello");
// 	ft_putstr("\n");
// 	ft_putstr("world!!");
// }
