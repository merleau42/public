/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exam.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keunykim <keunykim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 21:32:51 by keunykim          #+#    #+#             */
/*   Updated: 2023/12/15 04:52:57 by keunykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int ft_strcmp(char* s1, char* s2)
{
	int i;
	
	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			break;
		i++;
	}
	return s1[i] - s2[i];
}

int main(int argc, char **argv)
{
	int argn;
	int i;
	char *tmp;
	int sorted;

	if (argc >= 2)
	{
		sorted = 0;
		while (sorted == 0)
		{
			sorted = 1;
			argn = 2;
			while (argn <= argc - 1)
			{
				if (ft_strcmp(argv[argn-1], argv[argn]) > 0)
				{
					tmp = argv[argn];
					argv[argn] = argv[argn - 1];
					argv[argn - 1] = tmp;
					sorted = 0;
				}
				argn++;
			}
		}
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
	}
	return 0;
}