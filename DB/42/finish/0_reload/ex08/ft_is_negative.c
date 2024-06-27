/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keunykim <keunykim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:42:09 by keunykim          #+#    #+#             */
/*   Updated: 2024/02/22 21:39:18 by keunykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

// #include <unistd.h>
// void ft_putchar(char c)
// {
// 	write(1,&c,1);
// }

void	ft_is_negative(int n)
{
	if (n >= 0)
		ft_putchar('P');
	else
		ft_putchar('N');
}

// int	main(void)
// {
// 	ft_is_negative(-2147483648);
//     ft_is_negative(-2147483647);
//     ft_is_negative(-2147483646);
//     ft_is_negative(-1234);
//     ft_is_negative(-10);
//     ft_is_negative(-9);
//     ft_is_negative(-8);
//     ft_is_negative(-7);
//     ft_is_negative(-6);
//     ft_is_negative(-5);
//     ft_is_negative(-4);
//     ft_is_negative(-3);
//     ft_is_negative(-2);
//     ft_is_negative(-1);
//     write(1,"\n",1);
//     ft_is_negative(-0);
//     ft_is_negative(0);
//     write(1,"\n",1);
//     ft_is_negative(2147483647);
//     ft_is_negative(2147483646);
//     ft_is_negative(1234);
//     ft_is_negative(10);
//     ft_is_negative(9);
//     ft_is_negative(8);
//     ft_is_negative(7);
//     ft_is_negative(6);
//     ft_is_negative(5);
//     ft_is_negative(4);
//     ft_is_negative(3);
//     ft_is_negative(2);
//     ft_is_negative(1);
// 	return (0);
// }
