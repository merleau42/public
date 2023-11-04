#include <stdio.h>
#include <stdlib.h>
int *ft_map(int *tab, int length, int(*f)(int))
{
	int	i;
	int	*array;
	
	if (tab == NULL || f == NULL)
		return (NULL);
	i = 0;
	array = (int *)malloc(length * sizeof(int));
	if (array == NULL)
		return (NULL);
	while (i < length)
	{
		array[i] = f(tab[i]);
		i++;
	}
	return (array);
}
