CC = cc
AR = ar
CFLAGS = -Wall -Wextra -Werror
ARFLAGS = crs
RM = rm -f

HEAD_DIR := ./
INC = -I$(HEAD_DIR)

NAME					= libft.a

MAN_SRCS				= ft_atoi.c \
						ft_bzero.c \
						ft_isalnum.c \
						ft_isalpha.c \
						ft_isascii.c \
						ft_isdigit.c \
						ft_isprint.c \
						ft_memchr.c \
						ft_memcmp.c \
						ft_memcpy.c \
						ft_memmove.c \
						ft_memset.c \
						ft_strchr.c \
						ft_strlcat.c \
						ft_strlcpy.c \
						ft_strlen.c \
						ft_strncmp.c \
						ft_strnstr.c \
						ft_strrchr.c \
						ft_tolower.c \
						ft_toupper.c \
						ft_calloc.c \
						ft_strdup.c \
						ft_substr.c \
						ft_strjoin.c \
						ft_strtrim.c \
						ft_itoa.c \
						ft_strmapi.c \
						ft_split.c \
						ft_putchar_fd.c \
						ft_putstr_fd.c \
						ft_striteri.c \
						ft_putendl_fd.c \
						ft_putnbr_fd.c

BNS_SRCS				= ft_lstsize.c \
						ft_lstadd_back.c \
						ft_lstadd_front.c \
						ft_lstclear.c \
						ft_lstdelone.c \
						ft_lstiter.c \
						ft_lstlast.c \
						ft_lstmap.c \
						ft_lstnew.c

ifdef WITH_BONUS
SRCS = $(MAN_SRCS) $(BNS_SRCS)
else
SRCS = $(MAN_SRCS)
endif

all :   $(NAME)

OBJS				= $(SRCS:%.c=%.o)

$(NAME)		:	$(OBJS)
			$(AR) $(ARFLAGS) $(NAME) $(OBJS)

$(OBJS) :
	$(CC) $(CFLAGS) $(INC) -c $(SRCS)

bonus:
	make WITH_BONUS=1 all

#bonus	:	$(NAME)
#		$(CC) $(CFLAGS) -c $(BNS_SRCS) -I./
#		$(AR) $(ARFLAGS) $(NAME) $(BNS_OBJS)

clean	:
		$(RM) $(MAN_SRCS:%.c=%.o) $(BNS_SRCS:%.c=%.o)

fclean	:	clean
		$(RM) $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re bonus
