NAME = client server
SRCS = client.c server.c ft_printf.c

all: $(NAME)

$(NAME):
	make client
	make server

client: client.c ft_printf.c minitalk.h
	cc -Wall -Wextra -Werror -o $@

server: server.c ft_printf.c minitalk.h
	cc -Wall -Wextra -Werror -o $@

clean:
	rm -f $(OBJS)

fclean:
	make clean
	rm -f $(NAME)

re:
	make fclean
	make all

.PHONY: all clean fclean re
