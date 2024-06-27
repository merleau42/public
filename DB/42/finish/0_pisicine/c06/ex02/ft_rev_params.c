/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_param.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keunykim <keunykim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 17:50:15 by keunykim          #+#    #+#             */
/*   Updated: 2023/12/22 05:15:12 by keunykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;
	int	argn;

	argn = argc - 1;
	while (argn >= 1)
	{
		i = 0;
		while (argv[argn][i] != '\0')
		{
			write(1, &argv[argn][i], 1);
			i++;
		}
		write(1, "\n", 1);
		argn--;
	}
	return (0);
}
