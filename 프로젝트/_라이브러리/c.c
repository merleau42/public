#include <stdio.h>

int main() {
    char c = 'A';

    printf("%5d\n", c);
    printf("%-5d\n", c);
    printf("%05d\n", c);
    printf("% 5d\n", c);
    printf("%15d\n", c);

}