#include "../../integrate/libft.c"
#include <stdio.h>

int main()
{
	char* t = "hello";

	printf("%s\n", t);
	printf("%p", ft_strchr(t, '\0'));
}