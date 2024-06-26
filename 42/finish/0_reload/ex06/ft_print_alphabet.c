/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keunykim <keunykim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:25:40 by keunykim          #+#    #+#             */
/*   Updated: 2024/02/20 16:50:50 by keunykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

// #include <unistd.h>
// void ft_putchar(char c)
// {
// 	write(1,&c,1);
// }

void	ft_print_alphabet(void)
{
	char	az;

	az = 'a';
	while (az <= 'z')
		ft_putchar(az++);
}

// int	main(void)
// {
// 	ft_print_alphabet();
// 	return (0);
// }
