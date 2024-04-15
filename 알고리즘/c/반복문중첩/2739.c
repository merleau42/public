#include <stdio.h>

int main()
{
	int i, j;
	int a, b;

	scanf("%d", &a);

	i = a;
	while (i <= a)
	{
		j = 1;
		while (j <= 9)
		{
			printf("%d * %d = %d\n", i, j, i*j);
			j++;
		}
		i++;
	}
}