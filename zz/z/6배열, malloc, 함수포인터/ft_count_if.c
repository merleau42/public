#include <stdio.h>
#include <stdlib.h>

int ft_count_if(char **tab, int length, int(*f)(char *))
{
    int i;
    int count;
    
    i = 0;
    count = 0;
    if (tab == NULL || f == NULL || length == 0)
        return (0);
    while (i < length)
    {
        if (f(tab[i]))
            count++;
        i++;
    }
    return (count);   
}
