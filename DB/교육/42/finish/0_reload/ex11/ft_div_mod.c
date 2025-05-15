/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keunykim <keunykim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:05:25 by keunykim          #+#    #+#             */
/*   Updated: 2024/02/22 21:40:34 by keunykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}

// #include <stdio.h>
// int main(void)
// {
// 	int res_div;
// 	int res_mod;
//
// 	ft_div_mod(66, 7, &res_div, &res_mod);
//
// 	printf("66 // 7 == %d\n66 MOD 7 == %d", res_div, res_mod);
// }
