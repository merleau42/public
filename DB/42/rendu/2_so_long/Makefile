INC=%%%%
INCLIB=$(INC)/../lib

CFLAGS = -Werror -Wextra -Wall

all:
	make -C ./minilibx-linux
	cp ./minilibx-linux/libmlx_Linux.a ./libmlx_Linux.a
	cc $(CFLAGS) libmlx_Linux.a main.c -o so_long

clean:
	make -C ./minilibx-linux clean
	rm libmlx_Linux.a
	rm so_long

re:
	make clean
	make -C ./minilibx-linux all
	


############################


# NAME= so_long
# SRC = main.c
# OBJ = $(SRC:%.c=%.o)

# LFLAGS = -L.. -lmlx -L$(INCLIB) -lXext -lX11 -lm -lbsd
# # LFLAGS += -lbsd

# all: $(NAME)

# $(NAME): $(OBJ)
# 	cc -o $(NAME) $(OBJ) $(LFLAGS)

# clean:
# 	rm -f $(NAME) $(OBJ) *~ core *.core

# re: clean all
