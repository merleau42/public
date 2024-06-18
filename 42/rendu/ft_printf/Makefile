CC = cc
AR = ar
RM = rm -f
CP = cp

NAME = libftprintf.a
ARFLAGS= rcs

HEAD_DIR := ./includes
INC = -I$(HEAD_DIR)
CFLAGS = -Wall -Wextra -Werror $(INC)

SRCS_DIR := ./srcs

MAN_SRCS = ft_printf.c \
		   ft_intlen_base.c \
		   ft_unsigned_intlen_base.c \
		   ft_has_percent.c \
		   ft_read_spec.c \
		   ft_handle_str.c \
		   ft_handle_char.c \
		   ft_handle_decimal.c \
		   ft_handle_pointer.c \
		   ft_handle_percent.c \
		   ft_handle_unsigned_base.c \
		   ft_itoa_base.c

BNS_SRCS =

ifdef WITH_BONUS
SRCS = $(addprefix $(SRCS_DIR)/, $(MAN_SRCS)) $(addprefix $(SRCS_DIR)/, $(BNS_SRCS))
else
SRCS = $(addprefix $(SRCS_DIR)/, $(MAN_SRCS))
endif

OBJS_DIR := ./srcs
OBJS = $(SRCS:.c=.o)

LIB_DIR := ./libft
LIB_NAME = libft.a

INC = -I$(HEAD_DIR)

MAKE = make

all : $(NAME)

$(NAME) : $(OBJS)
	$(MAKE) -C $(LIB_DIR) bonus
	$(CP) $(LIB_DIR)/$(LIB_NAME) $@
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

$(OBJS_DIR)/%.o : %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIB_DIR) clean

fclean :
	$(RM) $(OBJS)
	$(RM) $(NAME)
	$(MAKE) -C $(LIB_DIR) fclean

re : fclean all

.PHONY : all clean fclean re bonus
