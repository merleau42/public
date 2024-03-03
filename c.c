#include <stdio.h>
#include <unistd.h>

int main()
{
    printf("%d\n", (p = &a, *p));
    printf("%d\n", (p = &b, *p));
    printf("%d\n", (p = &c, *p));

    printf("%d\n", (q = &a, *q));
    printf("%d\n", (q = &b, *q));
    printf("%d\n", (q = &c, *q));
}