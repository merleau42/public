#include <stdio.h>
#include <string.h>


int main() {
    int *p;
    
    p = malloc(0);

    printf("%p\n", p);
    printf("%p\n", (void*) 0);
    printf("%p\n", (void*) 0+ 1);
    printf("%p\n", (void*) 0+ 2);
    printf("%p\n", (void*) 0+ 3);

    free(p);
    printf("free1\n");

    free(NULL);
    printf("free2");

    return 0;
}
