#include "_board.c"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
/// 연습장 (출력, 문법, 노미, 확인)

int main2()
{
	//:  ft_strncmp
	printf("%d ", ft_strncmp("Hello", "Hi", 2) < 0);
	printf("%d ", ft_strncmp("Hello", "Hi", 1) == 0);
	printf("%d ", ft_strncmp("Hello", "World", 0) == 0);
	printf("%d ", ft_strncmp("Hello^", "Hello$", 5) == 0);
	printf("%d ", ft_strncmp(" ", "\200", 1) < 0);
	printf("%d ", ft_strncmp(" ", "\200", 0) == 0);
	printf("%d ", ft_strncmp("Hello", "Hello", 424242424) == 0);
	printf("%d\n\n", ft_strncmp("Hello ", "Hello", 424242424));

	printf("%d ", ft_strncmp("Hello", "Hi", 2));
	printf("%d ", ft_strncmp("Hello", "Hi", 1));
	printf("%d ", ft_strncmp("Hello", "World", 0));
	printf("%d ", ft_strncmp("Hello^", "Hello$", 5));
	printf("%d ", ft_strncmp(" ", "\200", 1));
	printf("%d ", ft_strncmp(" ", "\200", 0));
	printf("%d ", ft_strncmp("Hello", "Hello", 424242424));
	printf("%d\n\n", ft_strncmp("Hello ", "Hello", 424242424));
	return 0;
}

int main()
{
	int set[24][4];
	int i;
	char *a;
	char *b;

	a = "123412431324134214231432213421432314234124132431";
	b = "312431423214324134123421412341324213423143124321";
	i = -1;
	while (i++ < 95)
		set[i / 4][i % 4] = a[i % 48] * (i < 48) + b[i % 48] * (i >= 48);

	for (int i = 0; i < 24; i++)
	{
		for (int j = 0; j < 4; j++)
			printf("%c ", set[i][j]);
		printf("\n");
	}
}