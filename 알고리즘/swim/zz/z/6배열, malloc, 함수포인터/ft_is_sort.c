#include <stdio.h>
#include <stdlib.h>

int is_bigger(int n1, int n2)
{
    return (n1 - n2);
}

int ft_is_sort(int *tab, int length, int (*f)(int, int))
{
    int i;
    
    i = 0;
    if(tab == NULL || length == 0 || f == NULL)
        return (0);
    while(i < length - 1)
    {
        if (f(tab[i], tab[i + 1]) > 0)
            return (0);
        i++;     
    }
    return (1);
}

int main(void)
{
    int array[] = {3, 3};
    int size = 2;

    printf("%d\n", ft_is_sort(array, size, &is_bigger));
}