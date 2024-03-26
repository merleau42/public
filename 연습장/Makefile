NAME = libft.a

CFILE =	ft_isalnum.c ft_isalpha.c ft_isdigit.c ft_isascii.c ft_isprint.c \
		ft_tolower.c ft_toupper.c \
		ft_bzero.c ft_memset.c ft_calloc.c \
		ft_strlen.c \
		ft_strchr.c ft_strrchr.c ft_memchr.c ft_strnstr.c ft_strncmp.c ft_memcmp.c \
		ft_strdup.c ft_strlcpy.c ft_strlcat.c ft_memcpy.c ft_memmove.c \
		ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c \
		ft_strmapi.c ft_striteri.c \
		ft_atoi.c ft_itoa.c \
		ft_putchar_fd.c	ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c \
#BFILE = 보너스1.c 보너스2.c ....

ifdef BNS
	OFILE = $(CFILE:%.c=%.o) $(BFILE:%.c=%.o)
else
	OFILE = $(CFILE:%.c=%.o)
endif

$(NAME)	:	$(OFILE)
		ar rc libft.a $(OFILE)

%.o : %.c
		cc -Werror -Wextra -Wall -c $< -I./ -o $@

all	:	$(NAME)

clean	:
		rm -f $(OFILE)

fclean	:	clean
		rm -f $(NAME)

re	:	fclean all

bonus :
	make BNS=yes
	make $(NAME)

.PHONY	:	all clean fclean re bonus