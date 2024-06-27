NAME = libft.a

CFILE = ft_atoi.c ft_itoa.c \
	ft_bzero.c ft_memset.c \
	ft_tolower.c ft_toupper.c \
	ft_isalnum.c ft_isalpha.c ft_isdigit.c ft_isascii.c ft_isprint.c \
	ft_strlen.c \
	ft_memcpy.c ft_memmove.c \
	ft_strlcpy.c ft_strlcat.c \
	ft_strdup.c ft_substr.c \
	ft_strjoin.c ft_strtrim.c ft_split.c \
	ft_strchr.c ft_strrchr.c ft_memchr.c ft_strnstr.c \
	ft_strmapi.c ft_striteri.c \
	ft_memcmp.c ft_strncmp.c \
	ft_calloc.c \
	ft_putchar_fd.c	ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c \

BFILE = ft_lstnew.c \
	ft_lstadd_back.c ft_lstadd_front.c \
	ft_lstsize.c ft_lstlast.c \
	ft_lstclear.c ft_lstdelone.c \
	ft_lstmap.c ft_lstiter.c \

ifdef BNS
	OFILE = $(CFILE:%.c=%.o) $(BFILE:%.c=%.o)
else
	OFILE = $(CFILE:%.c=%.o)
endif

$(NAME) : $(OFILE)
		ar rc libft.a $(OFILE)

%.o : %.c
		cc -Werror -Wextra -Wall -c $< -I./ -o $@

all : $(NAME)

bonus :
	make BNS=yes
	make $(NAME)

clean :
		rm -f $(CFILE:%.c=%.o) $(BFILE:%.c=%.o)

fclean : clean
		rm -f $(NAME)

re :
	make fclean
	make all

so :
	cc -nostartfiles -fPIC -Werror -Wextra -Wall $(CFILE) $(BFILE)
	gcc -nostartfiles -shared -o libft.so $(OFILE)

.PHONY : all clean fclean re bonus