#include <unistd.h>

void	ft_putstr(char *str);
int		ft_strcmp(char *s1, char *s2);

//ac가 N개이면, 0번째 인자에 이름이 들어가므로, N번째 인자는 N-1인덱스에 있음
int		main(int ac, char **av)
{
	ft_putstr(av[0]); // 파일명 출력
			
	if (ac > 1) //인자를 1개 "이상" 받았음
	{
		int i=1;
		while (av[ac - 1][i])	write(1, av[ac - 1][i]++, 1); // 마지막 인자 출력

		while (i < ac)
			ft_putstr(av[i++]); 		// 모든 인자 순서대로 출력
			ft_putstr(av[ac - i--]);	// 모든 인자 역순으로 출력
		
		char *str;
		while (i < ac - 1)	// 모든 인자 정렬
		{
			if (ft_strcmp(av[i], av[i + 1]) > 0)
			{
				str = av[i];
				av[i] = av[i + 1];
				av[i + 1] = str;
				i = 1;
			}
			else
				i++;
		}
	}
	
	// do-op
	if (ac == 4)
	{
		if (*av[2] == '+')
			printf("%d", atoi(av[1]) + atoi(av[3]));
		else if (*av[2] == '-')
			printf("%d", atoi(av[1]) - atoi(av[3]));
		else if (*av[2] == '*')
			printf("%d", atoi(av[1]) * atoi(av[3]));
		else if (*av[2] == '/')
			printf("%d", atoi(av[1]) / atoi(av[3]));
		else if (*av[2] == '%')
			printf("%d", atoi(av[1]) % atoi(av[3]));
	}
	write(1, "\n", 1);
	return (0);
}
