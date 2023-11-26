#include <unistd.h>
#include <stdio.h>
#include <limits.h>

void	swap(int *a, int *b)
{
	int	aux;

	aux = *a;
	*a = *b;
	*b = aux;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	min;
	int	pos_min;
	int	i;
	int	k;

	i = 0;
	k = 1;
	pos_min = 0;
	while (i < size - 1)
	{
		min = tab[i];
		k = i + 1;
		while (k < size)
		{
			if (tab[k] < min)
			{
				min = tab[k];
				pos_min = k;
			}
			k++;
		}
		if (min != tab[i])
			swap(&tab[pos_min], &tab[i]);
		i++;
	}
}

