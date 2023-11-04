/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keunkim <keunkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 11:22:37 by keunkim           #+#    #+#             */
/*   Updated: 2023/08/05 15:07:51 by keunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_kth_while(int K, int N, char *dec)
{
	dec[K] = dec[K - 1] + 1;
	while (dec[K] <= K + '9' - N)
	{
		if (K != N)
			ft_kth_while(K + 1, N, dec);
		if (K == N)
		{
			write(1, dec + 1, N);
			if (dec[N] + dec[1] != 1 + '9' - N + '9')
				write(1, ", ", 2);
		}
		dec[K]++;
	}
}

void	ft_print_combn(int n)
{
	char	dec[11];

	dec[0] = '0' - 1;
	ft_kth_while(1, n, dec);
}
