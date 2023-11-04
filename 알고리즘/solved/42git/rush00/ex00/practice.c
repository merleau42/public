#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char *c)
{	
	write(1, c, 1);
}

void	rush00(int x, int y)
{
	printf("rush00(%d,%d)\n",x,y);
	int	i;
	int	j;

	if (x <= 0 || y <= 0)
		write(1, "invalid input!!\n", 16);
	i = 0;
	while (i++ <= y - 1)
	{
		j = 0;
		while (j++ <= x - 1)
		{
			if ((i == 1 || i == y) && (j == 1 || j == x))
				ft_putchar("o");
			if ((i == 1 || i == y) && j != 1 && j != x)
				ft_putchar("-");
			if ((i != 1 && i != y) && (j == x || j == 1))
				ft_putchar("|");
			if ((i != 1 && i != y) && j != 1 && j != x)
				ft_putchar(" ");
		}
		ft_putchar("\n");
	}
		ft_putchar("\n");
}

void	rush01(int x, int y)
{
	printf("rush01(%d,%d)\n",x,y);
	int	i;
	int	j;

	if (x <= 0 || y <= 0)
		write(1, "invalid input!!\n", 16);
	i = 0;
	while (i++ <= y - 1)
	{
		j = 0;
		while (j++ <= x - 1)
		{
//			if ((i == 1 && j == 1) || (i == y && j == x) && !(j==1 && x==1) && !(i==1 && y==1))
			if ((i * j < 2) || (i * j == x * y) && (j * x > 1) && (i * y > 1))
				ft_putchar("/");
//			else if (((i == 1 && j==x) || (i == y && j == 1)) && !(i==1 && j==1))
			else if (((i == 1 && j == x) || (i == y && j == 1)) && i * j != 1)
				ft_putchar("\\");
			else if ((i != 1 && i != y) && j != 1 && j != x)
				ft_putchar(" ");
			else
				ft_putchar("*");
		}
		ft_putchar("\n");
	}
		ft_putchar("\n");
}

void	rush02(int x, int y)
{
	printf("rush02(%d,%d)\n",x,y);
	int	i;
	int	j;

	if (x <= 0 || y <= 0)
		write(1, "invalid input!!\n", 16);
	i = 0;
	while (i++ <= y - 1)
	{
		j = 0;
		while (j++ <= x - 1)
		{
			if (1 != y && i == y && (j == 1 || j == x))
				ft_putchar("C");
			else if (i == 1 && (j == 1 || j == x))
				ft_putchar("A");
			else if ((i != 1 && i != y) && j != 1 && j != x)
				ft_putchar(" ");
			else
				ft_putchar("B");
		}
		ft_putchar("\n");
	}
		ft_putchar("\n");
}

void	rush03(int x, int y)
{
	printf("rush03(%d,%d)\n",x,y);
	int	i;
	int	j;

	if (x <= 0 || y <= 0)
		write(1, "invalid input!!\n", 16);
	i = 0;
	while (i++ <= y - 1)
	{
		j = 0;
		while (j++ <= x - 1)
		{
			if ((i == 1 && j == 1) || (i == y && j == 1))
				ft_putchar("A");
			else if ((i == 1 || i == y) && j == x && j != 1)
				ft_putchar("C");
			else if ((i != 1 && i != y) && j != 1 && j != x)
				ft_putchar(" ");
			else
				ft_putchar("B");
		}
		ft_putchar("\n");
	}
		ft_putchar("\n");
}

void	rush04(int x, int y)
{
	printf("rush04(%d,%d)\n",x,y);
	int	i;
	int	j;

	if (x <= 0 || y <= 0)
		write(1, "invalid input!!\n", 16);
	i = 0;
	while (i++ <= y - 1)
	{
		j = 0;
		while (j++ <= x - 1)
		{
//			if ((i == 1 && j == 1) || (i == y && j == x) && !(j==1 && i!=1) && !(j==x && i==1))
			if (i * j < 2 | i * j == x * y & (j > 1 | i < 2) & (j != x | i > 1))
				ft_putchar("A");
//			else if (((i == y && j == 1) || (i == 1 && j == x)) && !(x==1 && j==x && i==1) && !(y==1 && j==1))
			else if (i == y & j == 1 & j * y > 1 | j == x & i == 1 & j * y > 1)
				ft_putchar("C");
			else if ((i != 1 && i != y) && j != 1 && j != x)
				ft_putchar(" ");
			else
				ft_putchar("B");
		}
		ft_putchar("\n");
	}
		ft_putchar("\n");
}

int	main(void)
{
	rush00(0, 0);
	rush00(1, 1);

	rush00(1, 2);
	rush00(1, 3);
	rush00(1, 4);
	rush00(2, 1);
	rush00(3, 1);
	rush00(4, 1);

	rush00(2, 2);

	rush00(2, 3);
	rush00(2, 4);
	rush00(3, 2);
	rush00(4, 2);

	rush00(3, 3);
	rush00(3, 4);

	rush00(4, 3);
	rush00(4, 4);

	rush00(10, 5);
	rush00(12, 12);
	
	printf("\n\n");

	rush01(0, 0);
	rush01(1, 1);

	rush01(1, 2);
	rush01(1, 3);
	rush01(1, 4);
	rush01(2, 1);
	rush01(3, 1);
	rush01(4, 1);

	rush01(2, 2);

	rush01(2, 3);
	rush01(2, 4);
	rush01(3, 2);
	rush01(4, 2);

	rush01(3, 3);
	rush01(3, 4);
	rush01(4, 3);
	rush01(4, 4);

	rush01(10, 5);
	rush01(12, 12);
	
	printf("\n\n");
	rush02(0, 0);
	rush02(1, 1);

	rush02(1, 2);
	rush02(1, 3);
	rush02(1, 4);
	rush02(2, 1);
	rush02(3, 1);
	rush02(4, 1);

	rush02(2, 2);
	rush02(2, 3);
	rush02(2, 4);
	rush02(3, 2);
	rush02(4, 2);

	rush02(3, 3);
	rush02(3, 4);
	rush02(4, 3);

	rush02(4, 4);

	rush02(10, 5);
	rush02(12, 12);
	
	printf("\n\n");
	rush03(0, 0);
	rush03(1, 1);

	rush03(1, 2);
	rush03(1, 3);
	rush03(1, 4);
	rush03(2, 1);
	rush03(3, 1);
	rush03(4, 1);

	rush03(2, 2);
	rush03(2, 3);
	rush03(2, 4);
	rush03(3, 2);
	rush03(4, 2);

	rush03(3, 3);
	rush03(3, 4);
	rush03(4, 3);

	rush03(4, 4);

	rush03(10, 5);
	rush03(12, 12);
	
	printf("\n\n");
	rush04(0, 0);
	rush04(1, 1);

	rush04(1, 2);
	rush04(1, 3);
	rush04(1, 4);
	rush04(2, 1);
	rush04(3, 1);
	rush04(4, 1);

	rush04(2, 2);
	rush04(2, 3);
	rush04(2, 4);
	rush04(3, 2);
	rush04(4, 2);

	rush04(3, 3);
	rush04(3, 4);
	rush04(4, 3);

	rush04(4, 4);

	rush04(10, 5);
	rush04(12, 12);
	
	printf("\n\n");

	return (0);
}