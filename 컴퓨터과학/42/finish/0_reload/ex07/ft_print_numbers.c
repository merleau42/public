/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keunykim <keunykim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:39:48 by keunykim          #+#    #+#             */
/*   Updated: 2024/02/20 16:50:45 by keunykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

// #include <unistd.h>
// void ft_putchar(char c)
// {
// 	write(1,&c,1);
// }

void	ft_print_numbers(void)
{
	char	az;

	az = '0';
	while (az <= '9')
		ft_putchar(az++);
}

// int	main(void)
// {
// 	ft_print_numbers();
// 	return (0);
// }
