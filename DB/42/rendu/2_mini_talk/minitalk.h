/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keunykim <keunykim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 23:42:24 by keunykim          #+#    #+#             */
/*   Updated: 2024/06/28 23:44:25 by keunykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <stdint.h>
# include <stdio.h> // 지워라
# define BINARY "01"

typedef struct s_data {
    int		ascii;
    int		bit_count;
    char	buff[101];
    int		buff_idx;
} t_data;

size_t	ft_strlen(const char *str);
int		ft_atoi(const char *nptr);
char	*ft_putnbr_minitalk(size_t nbr, const char *base);

#endif