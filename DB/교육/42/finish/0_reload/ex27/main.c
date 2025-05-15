/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keunykim <keunykim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 19:24:35 by keunykim          #+#    #+#             */
/*   Updated: 2024/02/23 19:24:37 by keunykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

void	error(int argc)
{
	if (argc == 1)
		write (1, "File name missing.\n", 19);
	else if (argc > 2)
		write (1, "Too many arguments.\n", 20);
}

int	main(int argc, char *av[])
{
	int		fd;
	char	buf[10000];
	int		i;
	int		bytes;

	i = 0;
	while (buf[i])
		buf[i++] = 0;
	error (argc);
	if (argc == 2)
	{
		fd = open(av[1], O_RDONLY);
		bytes = read(fd, buf, 9999);
		if (bytes == -1)
			write (1, "Cannot read file.\n", 18);
		else
		{
			write (1, buf, bytes);
			close (fd);
		}
	}
	return (0);
}
