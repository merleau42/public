#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../../goinfre/testc04/ex00/ft_strlen.c"
#include "../../goinfre/testc04/ex01/ft_putstr.c"
#include "../../goinfre/testc04/ex02/ft_putnbr.c"
#include "../../goinfre/testc04/ex03/ft_atoi.c"
#include "../../goinfre/testc04/ex04/ft_putnbr_base.c"
#include "../../goinfre/testc04/ex05/ft_atoi_base.c"

int main(void)
{
    // Test ft_strlen
    printf("===Testing ft_strlen...===\n");
    printf("Length of 'Hello World': ");
    fflush(stdout);
    printf("ft_strlen: %d, strlen: %lu\n",
        ft_strlen("Hello World"),
        strlen("Hello World"));
    printf("Length of '': ");
    fflush(stdout);
    printf("ft_strlen: %d, strlen: %lu\n",
        ft_strlen(""),
        strlen(""));

    // Test ft_putstr
    printf("\n===Testing ft_putstr...===\n");
    fflush(stdout);
    ft_putstr("Hello World\n");

    // Test ft_putnbr
    printf("\n===Testing ft_putnbr...===\n");
    fflush(stdout);
    ft_putnbr(12345);
    printf("\n");
    fflush(stdout);
    ft_putnbr(-12345);
    printf("\n");
    fflush(stdout);
    ft_putnbr(-2147483648);
    printf("\n");

    // Test ft_atoi
    printf("\n===Testing ft_atoi...===\n");
    printf("atoi of ' 12345': ");
    fflush(stdout);
    printf("ft_atoi: %d, atoi: %d\n", ft_atoi(" 12345"), atoi(" 12345"));
    printf("atoi of '-12345': ");
    fflush(stdout);
    printf("ft_atoi: %d, atoi: %d\n", ft_atoi("-12345"), atoi("-12345"));
    printf("atoi of '   +--12345': ");
    fflush(stdout);
    printf("ft_atoi: %d, expected: 12345\n", ft_atoi("   +--12345"));
    printf("atoi of '-2147483648': ");
    fflush(stdout);
    printf("ft_atoi: %d, atoi: %d\n", ft_atoi("-2147483648"), atoi("-2147483648"));

    // Test ft_putnbr_base
    printf("\n===Testing ft_putnbr_base...===\n");
    fflush(stdout);
    ft_putnbr_base(12345, "0123456789abcdef");
    printf("\n");
    fflush(stdout);
    ft_putnbr_base(12345, "01");
    printf("\n");
    fflush(stdout);
    ft_putnbr_base(-12345, "0123456789abcdef");
    printf("\n");
    fflush(stdout);
    ft_putnbr_base(-12345, "01");
    printf("\n");
    fflush(stdout);
    ft_putnbr_base(-2147483648, "0123456789abcdef");
    printf("\n");
    fflush(stdout);
    ft_putnbr_base(-2147483648, "01");
    printf("\n");

    // Test ft_atoi_base
    printf("\nTesting ft_atoi_base...\n");
    printf("atoi_base of '3039' in base '0123456789abcdef': %d\n", ft_atoi_base("3039", "0123456789abcdef"));
    printf("atoi_base of '---11000000111001' in base '01': %d\n", ft_atoi_base("---11000000111001", "01"));
    printf("atoi_base of '-80000000' in base '0123456789abcdef': %d\n", ft_atoi_base("-80000000", "0123456789abcdef"));
    
    return 0;
}