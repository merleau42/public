#include <stdio.h>
#include "../rendu/c02/ex00/ft_strcpy.c"
#include "../rendu/c02/ex01/ft_strncpy.c"
#include "../rendu/c02/ex02/ft_str_is_alpha.c"
#include "../rendu/c02/ex03/ft_str_is_numeric.c"
#include "../rendu/c02/ex04/ft_str_is_lowercase.c"
#include "../rendu/c02/ex05/ft_str_is_uppercase.c"
#include "../rendu/c02/ex06/ft_str_is_printable.c"
#include "../rendu/c02/ex07/ft_strupcase.c"
#include "../rendu/c02/ex08/ft_strlowcase.c"
#include "../rendu/c02/ex09/ft_strcapitalize.c"
#include "../rendu/c02/ex10/ft_strlcpy.c"
#include "../rendu/c02/ex11/ft_putstr_non_printable.c"
#include "../rendu/c02/ex12/ft_print_memory.c"

int main()
{
    char source[] = "Hello, world!";
    char destination[50];
    char destination_n[50];

    // Test ft_strcpy
    ft_strcpy(destination, source);
    printf("ft_strcpy: %s\n", destination);

    // Test ft_strncpy with n less than the length of source
    ft_strncpy(destination_n, source, 5);
    destination_n[5] = '\0'; // Ensure null termination
    printf("ft_strncpy (n < length): %s\n", destination_n);

    // Test ft_strncpy with n greater than the length of source
    ft_strncpy(destination_n, source, 20);
    printf("ft_strncpy (n > length): %s\n", destination_n);

    // Test ft_str_is_alpha
    printf("ft_str_is_alpha ('Hello'): %d\n", ft_str_is_alpha("Hello"));
    printf("ft_str_is_alpha ('Hello123'): %d\n", ft_str_is_alpha("Hello123"));

    // Test ft_str_is_numeric
    printf("ft_str_is_numeric ('12345'): %d\n", ft_str_is_numeric("12345"));
    printf("ft_str_is_numeric ('123a45'): %d\n", ft_str_is_numeric("123a45"));

    // Test ft_str_is_lowercase
    printf("ft_str_is_lowercase ('hello'): %d\n", ft_str_is_lowercase("hello"));
    printf("ft_str_is_lowercase ('helloWorld'): %d\n", ft_str_is_lowercase("helloWorld"));

    // Test ft_str_is_uppercase
    printf("ft_str_is_uppercase ('HELLO'): %d\n", ft_str_is_uppercase("HELLO"));
    printf("ft_str_is_uppercase ('HELLOworld'): %d\n", ft_str_is_uppercase("HELLOworld"));

    // Test ft_str_is_printable
    printf("ft_str_is_printable ('Hello'): %d\n", ft_str_is_printable("Hello"));
    printf("ft_str_is_printable ('Hello\\n'): %d\n", ft_str_is_printable("Hello\n"));

    // Test ft_strupcase
    char str_upcase[] = "hello world!";
    printf("ft_strupcase ('%s'): ", str_upcase);
    fflush(stdout);
    printf("%s\n", ft_strupcase(str_upcase));

    // Test ft_strlowcase
    char str_lowcase[] = "HELLO WORLD!";
    printf("ft_strlowcase ('%s'): ", str_lowcase);
    fflush(stdout);
    printf("%s\n", ft_strlowcase(str_lowcase));

    // Test ft_strcapitalize
    char str_capitalize[] = "heLlo woRld! 42fOo bAr";
    printf("ft_strcapitalize ('%s'): ", str_capitalize);
    fflush(stdout);
    printf("%s\n", ft_strcapitalize(str_capitalize));

    // Test ft_strlcpy
    char str_dest[50];
    printf("ft_strlcpy (size = 10): %u\n", ft_strlcpy(str_dest, "Hello World!", 10));
    printf("Copied string: %s\n", str_dest);

    // Test ft_putstr_non_printable
    printf("ft_putstr_non_printable ('Hello\\nWorld'): ");
    fflush(stdout);
    ft_putstr_non_printable("Hello\nWorld");
    printf("\n");

    // Test ft_putstr_non_printable with negative characters
    char str_with_negatives[] = { 'P', 'o', 's', -1, -65, 'i', 'v', 'e', 0 };
    printf("ft_putstr_non_printable ('Positive', -1, -65): ");
    fflush(stdout);
    ft_putstr_non_printable(str_with_negatives);
    printf("\n");

    // Test ft_print_memory
    char memory_data[] = "Example string..\x01 \x1F \x7F \x80 ";
    printf("ft_print_memory test:\n");
	fflush(stdout);
    ft_print_memory(memory_data, sizeof(memory_data));

    return 0;
}