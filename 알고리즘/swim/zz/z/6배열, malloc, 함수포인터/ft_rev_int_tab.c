#include <unistd.h>
//#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	aux;

	i = 0;
	while (i < size / 2)
	{
		aux = tab[size - i - 1];
		tab[size - i - 1] = tab[i];
		tab[i] = aux;
		i++;
	}
}
