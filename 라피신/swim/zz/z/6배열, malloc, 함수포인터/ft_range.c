#include <stdio.h>
#include <stdlib.h>

int	get_range(int min, int max)
{
	if (max < 0 && min > 0)
		return (min - max);
	else
		return (max - min);
}

void	fill_array(int *array, int range, int min)
{
	int	i;

	i = 0;
	while (i < range)
	{
		array[i] = min + i;
		i++;
	}
}

int	*ft_range(int min, int max)
{
	int	*array;
	int	n;

	if (min >= max)
		return (NULL);
	n = get_range(min, max);
	array = (int *)malloc(n * sizeof(int));
	if (array == NULL)
		return (NULL);
	fill_array(array, n, min);
	return (array);
}
