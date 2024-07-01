NAME = minitalk.a
OBJS = client.o server.o utils.o

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

%.o: %.c
	cc -Wall -Wextra -Werror -c $< -o $@

clean:
	rm $(OBJS)

fclean:
	rm $(OBJS) $(NAME)

re:
	make fclean
	make all

.PHONY:	all clean fclean re