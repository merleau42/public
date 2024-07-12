CFLAGS = -Werror -Wextra -Wall

all:
	make -C ./minilibx-linux
	cp ./minilibx-linux/libmlx_Linux.a ./libmlx_Linux.a
	cc $(CFLAGS) libmlx_Linux.a main.c -o so_long

clean:
	make -C ./minilibx-linux clean
	rm libmlx_Linux.a

fclean:
	make clean
	rm so_long

re:
	make fclean
	make -C ./minilibx-linux all