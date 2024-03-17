# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: keunykim <keunykim@student.42gyeongsan.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/23 21:24:43 by keunykim          #+#    #+#              #
#    Updated: 2024/02/23 21:30:14 by keunykim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c
OBJS = srcs/ft_putchar.o srcs/ft_swap.o srcs/ft_putstr.o srcs/ft_strlen.o srcs/ft_strcmp.o

all : libft.a

libft.a: $(OBJS)
	ar rcs libft.a $(OBJS)

srcs/%.o: srcs/%.c includes/ft.h
	cc -Werror -Wextra -Wall -Iincludes -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf libft.a

re: fclean all

.PHONY: all clean fclean re
