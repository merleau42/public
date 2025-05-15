NAME = client server
OBJS_ALL = client.o server.o ft_printf.o utils.o
OBJS_CLIENT = client.o ft_printf.o utils.o
OBJS_SERVER = server.o ft_printf.o utils.o
FLAG = -Wall -Wextra -Werror

all: $(NAME)

client: $(OBJS_CLIENT)
	cc $(FLAG) $(OBJS_CLIENT) -o client

server: $(OBJS_SERVER)
	cc $(FLAG) $(OBJS_SERVER) -o server

%.o: %.c
	cc $(FLAG) -c $< -o $@

clean:
	rm $(OBJS_ALL)

fclean: clean
	rm $(NAME)

re: fclean all

.PHONY: all clean fclean re