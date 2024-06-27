#include <stdio.h>
#include "../rendu/c01/ex00/ft_ft.c"
#include "../rendu/c01/ex01/ft_ultimate_ft.c"
#include "../rendu/c01/ex02/ft_swap.c"
#include "../rendu/c01/ex03/ft_div_mod.c"
#include "../rendu/c01/ex04/ft_ultimate_div_mod.c"
#include "../rendu/c01/ex05/ft_putstr.c"
#include "../rendu/c01/ex06/ft_strlen.c"
#include "../rendu/c01/ex07/ft_rev_int_tab.c"
#include "../rendu/c01/ex08/ft_sort_int_tab.c"

int main(void)
{
    int a, b, div, mod;
    char *str = "Hello";
    int array[] = {5, 3, 7, 1, 4};
    int size = sizeof(array) / sizeof(array[0]);
    int *ptr1;
    int **ptr2;
    int ***ptr3;
    int ****ptr4;
    int *****ptr5;
    int ******ptr6;
    int *******ptr7;
    int ********ptr8;
    int *********ptr9;

// Testing ft_putstr first due to buffer
    ft_putstr(str);
    printf("\n");

    // Initialize pointers for ft_ft and ft_ultimate_ft
    ptr1 = &a;
    ptr2 = &ptr1;
    ptr3 = &ptr2;
    ptr4 = &ptr3;
    ptr5 = &ptr4;
    ptr6 = &ptr5;
    ptr7 = &ptr6;
    ptr8 = &ptr7;
    ptr9 = &ptr8;

    // Testing ft_ft
    ft_ft(ptr1);
    printf("ft_ft test result: %d\n", a);

    // Resetting the value of 'a' for the next test
    a = 0;

    // Testing ft_ultimate_ft
    ft_ultimate_ft(ptr9);
    printf("ft_ultimate_ft test result: %d\n", a);

    // Resetting the value of 'a' and setting 'b' for ft_swap test
    a = 100;
    b = 200;

    // Testing ft_swap
    printf("Before ft_swap: a = %d, b = %d\n", a, b);
    ft_swap(&a, &b);
    printf("After ft_swap: a = %d, b = %d\n", a, b);

    // Setting values for ft_div_mod test
    a = 30;
    b = 7;

    // Testing ft_div_mod
    ft_div_mod(a, b, &div, &mod);
    printf("ft_div_mod test: %d / %d = %d, remainder = %d\n", a, b, div, mod);

    // Resetting values for ft_ultimate_div_mod test
    a = 30;
    b = 7;

    // Testing ft_ultimate_div_mod
    ft_ultimate_div_mod(&a, &b);
    printf("ft_ultimate_div_mod test: quotient = %d, remainder = %d\n", a, b);

    // Testing ft_strlen
    printf("ft_strlen test: Length of \"%s\" is %d\n", str, ft_strlen(str));

    // Testing ft_rev_int_tab
    printf("Original array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    ft_rev_int_tab(array, size);

    printf("Reversed array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    // Testing ft_sort_int_tab
    ft_sort_int_tab(array, size);

    printf("Sorted array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}