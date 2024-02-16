/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_param.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keunykim <keunykim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 05:09:33 by keunykim          #+#    #+#             */
/*   Updated: 2023/12/22 06:04:49 by keunykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			break ;
		i++;
	}
	return (s1[i] - s2[i]);
}

int	ft_print_params(int argc, char **argv)
{
	int	i;
	int	argn;

	argn = 1;
	while (argn <= argc - 1)
	{
		i = 0;
		while (argv[argn][i] != '\0')
		{
			write(1, &argv[argn][i], 1);
			i++;
		}
		write(1, "\n", 1);
		argn++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int		argn;
	int		sorted;
	char	*tmp;

	sorted = 0;
	while (sorted == 0)
	{
		sorted = 1;
		argn = 2;
		while (argn <= argc - 1)
		{
			if (ft_strcmp(argv[argn - 1], argv[argn]) > 0)
			{
				tmp = argv[argn];
				argv[argn] = argv[argn - 1];
				argv[argn - 1] = tmp;
				sorted = 0;
			}
			argn++;
		}
	}
	ft_print_params(argc, argv);
	return (0);
}
