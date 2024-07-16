CFLAGS = -Werror -Wextra -Wall
# LFLAGS = -Lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

all:
	make -C ./minilibx-linux
	cp ./minilibx-linux/libmlx_Linux.a ./libmlx_Linux.a
	cc $(CFLAGS) -I./minilibx-linux libmlx_Linux.a main.c -o so_long

clean:
	make -C ./minilibx-linux clean
	rm libmlx_Linux.a

fclean:
	make clean
	rm so_long

re:
	make fclean
	make -C ./minilibx-linux all


# ######

# %.o: %.c
# 	cc $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

# $(NAME): $(OBJ)
# 	cc $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)