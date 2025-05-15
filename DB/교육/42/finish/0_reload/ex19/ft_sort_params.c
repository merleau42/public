/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keunykim <keunykim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 17:33:14 by keunykim          #+#    #+#             */
/*   Updated: 2024/02/22 23:02:57 by keunykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char ch);

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
			ft_putchar(argv[argn][i]);
			i++;
		}
		ft_putchar('\n');
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
