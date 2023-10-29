#include "_board.c"
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//: C04
// #include <unistd.h>
// #include <stdio.h>
// #include "ex00/ft_strlen.c"
// #include "ex01/ft_putstr.c"
// #include "ex02/ft_putnbr.c"
// #include "ex03/ft_atoi.c"
// #include "ex04/ft_putnbr_base.c"
// #include "ex05/ft_atoi_base.c"

int main()
{
	// //: ft_putchar
	// ft_putchar('q');
	// ft_putchar('\n');

	// //: alphabet, reverse_alphabet, numbers
	// ft_print_alphabet();
	// ft_print_reverse_alphabet();
	// ft_print_numbers();
	// ft_putchar('\n');

	// //: ft_is_negative
	// ft_is_negative(-2147483648);
	// ft_is_negative(-2147483647);
	// ft_is_negative(-2147483646);
	// ft_is_negative(-12345678);
	// ft_is_negative(-2);
	// ft_is_negative(-1);
	// ft_is_negative(0);
	// ft_is_negative(1);
	// ft_is_negative(2);
	// ft_is_negative(12345678);
	// ft_is_negative(2147483646);
	// ft_is_negative(2147483647);
	// ft_putchar('\n');

	// //: ft_print_comb
	// ft_print_comb();
	// ft_putchar('\n');

	// //: ft_print_comb2
	// ft_print_comb2();
	// ft_putchar('\n');

	// //// ft_pow
	// ft_putnbr(ft_pow(3, 0));
	// ft_putnbr(ft_pow(3, 1));
	// ft_putnbr(ft_pow(3, 2));
	// ft_putnbr(ft_pow(3, 3));
	// ft_putnbr(ft_pow(3, 4));
	// ft_putnbr(ft_pow(3, 5));
	// ft_putchar('\n');

	// //: ft_putnbr
	// ft_putnbr(-2147483648);
	// ft_putnbr(-2147483647);
	// ft_putnbr(-2147483646);
	// ft_putnbr(-12345678);
	// ft_putnbr(-777777);
	// ft_putnbr(-44444);
	// ft_putnbr(-2);
	// ft_putnbr(-1);
	// ft_putnbr(0);
	// ft_putnbr(1);
	// ft_putnbr(2);
	// ft_putnbr(44444);
	// ft_putnbr(777777);
	// ft_putnbr(12345678);
	// ft_putnbr(2147483646);
	// ft_putnbr(2147483647);

	//: ft_print_comb
	// EXPLAIN_print_comb();
	ft_print_combn(1);
	ft_print_combn(2);
	ft_print_combn(3);
	ft_print_combn(4);
	// ft_print_combn(5);
	// ft_print_combn(6);
	// ft_print_combn(7);
	// ft_print_combn(8);
	// ft_print_combn(9);

	return 0;
}
int main01()
{
	int x;
	int foo, bar;

	//: ft_ft
	x=119;
	ft_putnbr(x);
	ft_ft(&x);
	ft_putnbr(x);

	//: ft_ultimate_ft
	x=777;
	int *p1 = &x;
	int **p2 = &p1;
	int ***p3 = &p2;
	int ****p4 = &p3;
	int *****p5 = &p4;
	int ******p6 = &p5;
	int *******p7 = &p6;
	int ********p8 = &p7;
	ft_ultimate_ft(&p8);
	ft_putnbr(x);

	//: ft_swap
	foo = 13; bar = 22;
	ft_putnbr(foo); ft_putnbr(bar);
	ft_swap(&foo, &bar);
	ft_putnbr(foo); ft_putnbr(bar);

	//: ft_div_mod
	int resA, resB;
	ft_div_mod(344, 3, &resA, &resB);
	ft_putnbr(resA); ft_putnbr(resB);

	//: ft_ultimate_div_mod
	foo = 1344; bar = 7;
	ft_ultimate_div_mod(&foo, &bar);
	ft_putnbr(foo); ft_putnbr(bar);

	//: ft_putstr,  ft_strlen
	ft_putstr("abcdefg\n");
	ft_putnbr( ft_strlen("abcdefg\n") );

	//: ft_rev_int_tab
	int arr[5] = {2, 3, 5, 7, 11};
	ft_rev_int_tab(arr, 5);
	for (int i = 0; i < 5; ++i)
		ft_putnbr(arr[i]);

	//: ft_sort_int_tab
	int brr[11] = {4, 1, 0, 9, 7, 2, 8, 3, 5, 6, -5};
	for (int i = 0; i < 11; ++i)
		printf("%d ", brr[i]);
	printf("\n");
	ft_sort_int_tab(brr, 11);
	for (int i = 0; i < 11; ++i)
		printf("%d ", brr[i]);
	printf("\n");

	return 0;
}
int main02()
{
	// char *origin = "pokemon\n";
	// char coppied1[30] = "11111111\n";
	// char coppied2[30] = "22222222\n";
	// char coppied3[30] = "33333333\n";
	// //  *ft_strcpy,  *ft_strncpy,  *ft_strlcpy 버전
	// ft_putstr(origin);
	// ft_putstr(coppied1);
	// ft_putstr( ft_strcpy(coppied1, origin) );
	// ft_putstr("------------\n");
	// ft_putstr(origin);
	// ft_putstr(coppied2);
	// ft_putstr( ft_strncpy(coppied2, origin, 5) );
	// ft_putstr( ft_strncpy(coppied2, "999444", 3) );
	// ft_putstr( ft_strncpy(coppied2, "555\n", 11) );
	// ft_putstr( ft_strncpy(coppied2, "7777", 0) );
	// ft_putstr("------------\n");
	// ft_putstr(origin);
	// ft_putstr(coppied3);
	// printf("%u sliced: %s\n", ft_strlcpy(coppied3, origin, 5), coppied3 );
	// printf("%u sliced: %s\n", ft_strlcpy(coppied3, "999444", 6), coppied3 );
	// printf("%u sliced: %s\n", ft_strlcpy(coppied3, "555qQS", 11), coppied3 );
	// printf("%u sliced: %s\n", ft_strlcpy(coppied3, "45678", 0), coppied3 );
	// printf("%u sliced: %s\n", ft_strlcpy(coppied3, "24687", 3), coppied3 );
	// printf("%u sliced: %s\n", ft_strlcpy(coppied3, "24687", 2), coppied3 );
	// printf("%u sliced: %s\n", ft_strlcpy(coppied3, "", 11), coppied3 );

	// // //  string.h 버전
	// ft_putstr(origin);
	// ft_putstr(coppied1);
	// ft_putstr( strcpy(coppied1, origin) );
	// ft_putstr("------------\n");
	// ft_putstr(origin);
	// ft_putstr(coppied2);
	// ft_putstr( strncpy(coppied2, origin, 5) );
	// ft_putstr( strncpy(coppied2, "999444", 3) );
	// ft_putstr( strncpy(coppied2, "555\n", 11) );
	// ft_putstr( strncpy(coppied2, "7777", 0) );
	// ft_putstr("------------\n");
	// ft_putstr(origin);
	// ft_putstr(coppied3);
	// printf("%lu sliced: %s\n", strlcpy(coppied3, origin, 5), coppied3 );
	// printf("%lu sliced: %s\n", strlcpy(coppied3, "999444", 6), coppied3 );
	// printf("%lu sliced: %s\n", strlcpy(coppied3, "555qQS", 11), coppied3 );
	// printf("%lu sliced: %s\n", strlcpy(coppied3, "45678", 0), coppied3 );
	// printf("%lu sliced: %s\n", strlcpy(coppied3, "24687", 3), coppied3 );
	// printf("%lu sliced: %s\n", strlcpy(coppied3, "24687", 2), coppied3 );
	// printf("%lu sliced: %s\n", strlcpy(coppied3, "", 11), coppied3 );

	// //  ft_str_is_alpha
	// ft_putnbr(ft_str_is_alpha(""));
	// ft_putnbr(ft_str_is_alpha("a"));
	// ft_putnbr(ft_str_is_alpha("A"));
	// ft_putnbr(ft_str_is_alpha("7"));
	// ft_putnbr(ft_str_is_alpha("nprt"));
	// ft_putnbr(ft_str_is_alpha("asdsadsadasd"));
	// ft_putnbr(ft_str_is_alpha("GSSEASADSASS"));
	// ft_putnbr(ft_str_is_alpha("456746543"));
	// ft_putnbr(ft_str_is_alpha("asdsa1sadasd"));
	// ft_putnbr(ft_str_is_alpha("sds da d"));

	// //  ft_str_is_numeric
	// ft_putnbr(ft_str_is_numeric(""));
	// ft_putnbr(ft_str_is_numeric("a"));
	// ft_putnbr(ft_str_is_numeric("A"));
	// ft_putnbr(ft_str_is_numeric("7"));
	// ft_putnbr(ft_str_is_numeric("nprt"));
	// ft_putnbr(ft_str_is_numeric("asdsadsadasd"));
	// ft_putnbr(ft_str_is_numeric("GSSEASADSASS"));
	// ft_putnbr(ft_str_is_numeric("456746543"));
	// ft_putnbr(ft_str_is_numeric("4567q6543"));
	// ft_putnbr(ft_str_is_numeric("456 65 4"));

	// // ft_str_is_lowercase
	// ft_putnbr(ft_str_is_lowercase(""));
	// ft_putnbr(ft_str_is_lowercase("a"));
	// ft_putnbr(ft_str_is_lowercase("A"));
	// ft_putnbr(ft_str_is_lowercase("7"));
	// ft_putnbr(ft_str_is_lowercase("nprt"));
	// ft_putnbr(ft_str_is_lowercase("asdsadsadasd"));
	// ft_putnbr(ft_str_is_lowercase("GSSEASADSASS"));
	// ft_putnbr(ft_str_is_lowercase("asDSsWWaAsd"));
	// ft_putnbr(ft_str_is_lowercase("456746543"));
	// ft_putnbr(ft_str_is_lowercase("4567q6543"));
	// ft_putnbr(ft_str_is_lowercase("456 65 4"));

	// //  ft_str_is_uppercase
	// ft_putnbr(ft_str_is_uppercase(""));
	// ft_putnbr(ft_str_is_uppercase("a"));
	// ft_putnbr(ft_str_is_uppercase("A"));
	// ft_putnbr(ft_str_is_uppercase("7"));
	// ft_putnbr(ft_str_is_uppercase("nprt"));
	// ft_putnbr(ft_str_is_uppercase("asdsadsadasd"));
	// ft_putnbr(ft_str_is_uppercase("GSSEASADSASS"));
	// ft_putnbr(ft_str_is_uppercase("asDSsWWaAsd"));
	// ft_putnbr(ft_str_is_uppercase("456746543"));
	// ft_putnbr(ft_str_is_uppercase("4567q6543"));
	// ft_putnbr(ft_str_is_uppercase("456 65 4"));

	// // ft_str_is_printable
	// char nprt[3] = {'\n'-2, ' '-1, '~'+1};
	// ft_putnbr(ft_str_is_printable(""));
	// ft_putnbr(ft_str_is_printable("a"));
	// ft_putnbr(ft_str_is_printable("A"));
	// ft_putnbr(ft_str_is_printable("7"));
	// ft_putnbr(ft_str_is_printable(nprt));
	// ft_putnbr(ft_str_is_printable("asdsadsadasd"));
	// ft_putnbr(ft_str_is_printable("GSSEASADSASS"));
	// ft_putnbr(ft_str_is_printable("asDSsWWaAsd"));
	// ft_putnbr(ft_str_is_printable("456746543"));
	// ft_putnbr(ft_str_is_printable("4567q6543"));
	// ft_putnbr(ft_str_is_printable("456 65 4"));

	// //  *ft_strupcase,   *ft_strlowcase
	// char msg1[50] = "P}oke_MOn vS. diGI:moN\n";
	// char msg2[50] = "P}oke_MOn vS. diGI:moN\n";
	// ft_putstr(msg1);
	// ft_putstr(ft_strupcase(msg1));
	// ft_putstr(ft_strlowcase(msg2));

	// //	 *ft_strcapitalize
	// char script1[100] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un\n";
	// char script2[100] = "1337 h4x0rz pwn j00!~pASS*wORD\n";
	// ft_putstr(ft_strcapitalize(script1));
	// ft_putstr(ft_strcapitalize(script2));

	// //  ft_putstr_non_printable
	// ft_putstr_non_printable("Coucou\ntu vas bien ?");
	// ft_putstr_non_printable("\r\t\b\f\v\177");

	// //  ft_print_memory
	// char *example2 = "Bonjour les aminches\t\n\tc\a est fou\ttout\tce qu on peut faire avec\t\n\tprint_memory\n\n\n\tlol.lol\n \0";
	// char *example3 = "Chuncheon is better than Seoul! :) ;)\0";
	// char *example4 = "Chuncheon ";
	// char *example5 = "Chuncheon is \0\0\0\0\0\0\0\0\0\0\0 Seoul! :) ;)";
	// char *example6 = "sample";
	// ft_print_memory(example2, 92); write(1,"\n",1);
	// ft_print_memory(example3, 38); write(1,"\n",1);
	// ft_print_memory(example4, 10); write(1,"\n",1);
	// ft_print_memory(example5, 37); write(1,"\n",1);
	// ft_print_memory(example6, 6);

	// hyunjunl ㅡ Exercise 11 (따로 실행)
	// ft_putstr_non_printable("Coucou\ntu vas bien ?");
	// ft_putstr_non_printable("\r\t\b\f\v\177");
	// printf("\n\n");

	// // hyunjunl ㅡ Exercise 00
	// char s1[20];
	// printf("%s", ft_strcpy(s1, "Hello World!\n"));
	// printf("%s\n", ft_strcpy(s1, ""));

	// // hyunjunl ㅡ Exercise 01
	// for (int i = 0; i < 19; ++i)
	// 	s1[i] = '#';
	// s1[19] = '\0';
	// printf("%s\n", ft_strncpy(s1, "Hello World!\n", 13));
	// printf("%s", ft_strncpy(s1, "Hello World!\n", 17));
	// for (int i = 0; i < 20; ++i)
	// 	printf("%d ", s1[i]);
	// printf("\n\n");

	// // hyunjunl ㅡ Exercise 02
	// printf("%d ", ft_str_is_alpha(""));
	// printf("%d ", ft_str_is_alpha("A"));
	// printf("%d ", ft_str_is_alpha("a"));
	// printf("%d ", ft_str_is_alpha("Z"));
	// printf("%d ", ft_str_is_alpha("z"));
	// printf("%d ", ft_str_is_alpha("A@a"));
	// printf("%d ", ft_str_is_alpha("z[Z"));
	// printf("%d ", ft_str_is_alpha("A`a"));
	// printf("%d\n\n", ft_str_is_alpha("z{Z"));

	// // hyunjunl ㅡ Exercise 03
	// printf("%d ", ft_str_is_numeric(""));
	// printf("%d ", ft_str_is_numeric("0"));
	// printf("%d ", ft_str_is_numeric("9"));
	// printf("%d ", ft_str_is_numeric("0/9"));
	// printf("%d\n\n", ft_str_is_numeric("9:0"));

	// // hyunjunl ㅡ Exercise 04
	// printf("%d ", ft_str_is_lowercase(""));
	// printf("%d ", ft_str_is_lowercase("a"));
	// printf("%d ", ft_str_is_lowercase("z"));
	// printf("%d ", ft_str_is_lowercase("a`z"));
	// printf("%d\n\n", ft_str_is_lowercase("z{a"));

	// // hyunjunl ㅡ Exercise 05
	// printf("%d ", ft_str_is_uppercase(""));
	// printf("%d ", ft_str_is_uppercase("A"));
	// printf("%d ", ft_str_is_uppercase("Z"));
	// printf("%d ", ft_str_is_uppercase("A@Z"));
	// printf("%d\n\n", ft_str_is_uppercase("Z[A"));

	// // hyunjunl ㅡ Exercise 06
	// printf("%d ", ft_str_is_printable("")); 
	// char s2[100];
	// for (int i = 32; i < 127; ++i)
	// 	s2[i - 32] = i;
	// s2[95] = s2[96] = '\0';
	// printf("%d ", ft_str_is_printable(s2));
	// s2[95] = 31;
	// printf("%d ", ft_str_is_printable(s2));
	// s2[95] = 127;
	// printf("%d\n\n", ft_str_is_printable(s2));

	// // hyunjunl ㅡ Exercise 07
	// ft_strcpy(s2, "");
	// printf("%s ", ft_strupcase(s2));
	// ft_strcpy(s2, "AaZz");
	// printf("%s ", ft_strupcase(s2));
	// ft_strcpy(s2, "AaZz@[`{AaZz");
	// printf("%s\n\n", ft_strupcase(s2));

	// // hyunjunl ㅡ Exercise 08
	// ft_strcpy(s2, "");
	// printf("%s ", ft_strlowcase(s2));
	// ft_strcpy(s2, "AaZz");
	// printf("%s ", ft_strlowcase(s2));
	// ft_strcpy(s2, "AaZz@[`{AaZz");
	// printf("%s\n\n", ft_strlowcase(s2));

	// // hyunjunl ㅡ Exercise 09
	// ft_strcpy(s2, "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un");
	// printf("%s\n\n", ft_strcapitalize(s2));

	// // hyunjunl ㅡ Exercise 10
	// int len = ft_strlcpy(s1, "Hello World!\n", 6);
	// printf("%s %d\n", s1, len);
	// for (int i = 0; i < 20; ++i)
	// 	s1[i] = '#';
	// len = ft_strlcpy(s1, "Hello World!\n", 20);
	// printf("%s %d\n", s1, len);
	// len = ft_strlcpy(s1, "Hello World!\n", 0);
	// printf("%s %d\n", s1, len);
	// for (int i = 0; i < 20; ++i)
	// 	printf("%d ", s1[i]);
	// printf("\n");

	// // // hyunjunl ㅡ Exercise 12 (따로 실행)
	// char arr[] = "Bonjour les aminches\t\n\tc\a est fou\ttout\tce qu on peut faire avec\t\n\tprint_memory\n\n\n\tlol.lol\n ";
	// if (ft_print_memory(arr, 92) != arr)
	// 	return -1;
	// char brr[] = "Chuncheon is better than Seoul! :) ;)";
	// ft_print_memory(brr, 38);
	// ft_print_memory(brr, 10);
	// ft_print_memory(brr, 0);
	// for (int i = 13; i < 24; ++i)
	// 	brr[i] = '\0';
	// ft_print_memory(brr, 37);

	// // 제공 테케
	// char	a[256];
	// a[0] = 0;
	// for(int i = 1; i < 257; i++)
	// 	a[i] = a[i - 1] + 1;

	// ft_print_memory(a, 256);
	return 0;
}
int main03()
{	// // Exercise 00
	// printf("%d ", ft_strcmp("Hello", "World") < 0);
	// printf("%d ", ft_strcmp("World", "Hello") > 0);
	// printf("%d ", ft_strcmp("Hello", "Hello") == 0);
	// printf("%d ", ft_strcmp("Hello", "Hello ") < 0);
	// printf("%d ", ft_strcmp("Hello ", "Hello") > 0);
	// printf("%d ", ft_strcmp("", "") == 0);
	// printf("%d ", ft_strcmp("", "\200") < 0);
	// printf("%d\n\n", ft_strcmp("\200", " ") > 0);

	// // Exercise 01
	// printf("%d ", ft_strncmp("Hello", "Hi", 2) < 0);
	// printf("%d ", ft_strncmp("Hello", "Hi", 1) == 0);
	// printf("%d ", ft_strncmp("Hello", "World", 0) == 0);
	// printf("%d ", ft_strncmp("Hello^", "Hello$", 5) == 0);
	// printf("%d ", ft_strncmp(" ", "\200", 1) < 0);
	// printf("%d ", ft_strncmp(" ", "\200", 0) == 0);
	// printf("%d ", ft_strncmp("Hello", "Hello", 424242424) == 0);
	// printf("%d\n\n", ft_strncmp("Hello ", "Hello", 424242424) > 0);

	// // Exercise 02
	// char arr[50];
	// for (int i = 0; i < 50; ++i)
	// 	arr[i] = '#';
	// arr[0] = '\0';
	// printf("%s\n", ft_strcat(arr, "Hello "));
	// printf("%s\n", ft_strcat(arr, "World!"));
	// printf("%s\n\n", ft_strcat(arr, ""));

	// // Exercise 03
	// char arr[50];
	// for (int i = 0; i < 50; ++i)
	// 	arr[i] = '#';
	// arr[0] = '\0';
	// printf("%s\n", ft_strncat(arr, "Hello World!", 6));
	// printf("%s\n", ft_strncat(arr, "World!", 0));
	// printf("%s\n\n", ft_strncat(arr, "World!", 424242424));

	// // Exercise 04
	// printf("%s", ft_strstr("", ""));
	// printf("%s\n", ft_strstr("Hello World!", ""));
	// printf("%s\n", ft_strstr("Hello World!", "World!"));
	// printf("%s\n", ft_strstr("Hello World!", " "));
	// printf("%s", ft_strstr("Hello World!", "o"));
	// printf("%s\n", ft_strstr("Hello World!", "!"));
	// printf("%p ", ft_strstr("Hello World!", "#"));
	// printf("%p ", ft_strstr("Hello World!", "h"));
	// printf("%p ", ft_strstr("Hello World!", "!#"));
	// printf("%p ", ft_strstr("Hello World!", "Hello#"));
	// printf("%p\n\n", ft_strstr("Hello World!", "Hello World!!"));
	
	// // Exercise 05
	char arr[50];
	for (int i = 0; i < 50; ++i)
		arr[i] = '#';
	arr[0] = '\0';
	int len = ft_strlcat(arr, "", 50);
	printf("%s %d\n", arr, len);
	len = ft_strlcat(arr, "Hello ", 50);
	printf("%s %d\n", arr, len);
	len = ft_strlcat(arr, "World!", 50);
	printf("%s %d\n", arr, len);
	len = ft_strlcat(arr, "", 50);
	printf("%s %d\n", arr, len);
	len = ft_strlcat(arr, "42", 0);
	printf("%s %d\n", arr, len);
	len = ft_strlcat(arr, "42", 3);
	printf("%s %d\n", arr, len);
	len = ft_strlcat(arr, "\nHello World!", 20);
	printf("%s %d\n", arr, len);
	len = ft_strlcat(arr, "World!", 20);
	printf("%s %d\n", arr, len);
	len = ft_strlcat(arr, "\nHello World!", 42);
	printf("%s %d\n", arr, len);
	for (int i = 31; i < 42; ++i)
		printf("%d ", arr[i]);
	printf("\n");
	return 0;
}
int main04()
{
	//: ft_atoi
	// // //> 양수가 기대되는 케이스
	// ft_putnbr(ft_atoi("12345- - -- 7654"));
	// ft_putnbr(ft_atoi("07"));
	// ft_putnbr(ft_atoi("   -+------+++-8764564-aaa"));
	// ft_putnbr(ft_atoi("2147483647"));
	// ft_putnbr(ft_atoi("\t\n\v\f\r +-+-1234z"));
	// ft_putnbr(ft_atoi("\t\n\v\f\r +-+-+1234z"));
	// ft_putnbr(ft_atoi("777"));
	// //> 음수가 기대되는 케이스
	// ft_putnbr(ft_atoi("-777"));
	// ft_putnbr(ft_atoi("\t\n\v\f\r +-+--1234z"));
	// ft_putnbr(ft_atoi("  -+++-+--+-8764564-aaa"));
	// ft_putnbr(ft_atoi(" ---+--+1234ab567"));
	// ft_putnbr(ft_atoi("-2147483648"));
	// //> 0이 기대되는 케이스
	// ft_putnbr(ft_atoi("-"));
	// ft_putnbr(ft_atoi("--"));
	// ft_putnbr(ft_atoi("+"));
	// ft_putnbr(ft_atoi("++"));
	// ft_putnbr(ft_atoi(" "));
	// ft_putnbr(ft_atoi("  -+++-"));
	// ft_putnbr(ft_atoi("  -+++-"));
	// ft_putnbr(ft_atoi(""));
	// ft_putnbr(ft_atoi("0"));
	// ft_putnbr(ft_atoi("-0"));
	// ft_putnbr(ft_atoi("000"));
	// //> 0이 기대되는 케이스 (부호뒤에, 부호/숫자가 아닌 문자)
	// ft_putnbr(ft_atoi(" --- 123"));
	// ft_putnbr(ft_atoi("-a123"));
	// ft_putnbr(ft_atoi("--w123"));

	//: ft_putnbr_base
	// ft_putnbr_base(405009,"0123456789");
	// ft_putnbr_base(70, "0123456789");
	// ft_putnbr_base(70, "012345678");
	// ft_putnbr_base(70, "01234567");
	// ft_putnbr_base(70, "zabcdefg");
	// ft_putnbr_base(70, "0123456");
	// ft_putnbr_base(70, "012345");
	// ft_putnbr_base(70, "01234");
	// ft_putnbr_base(70, "0123");
	// ft_putnbr_base(70, "012");
	// ft_putnbr_base(70, "01");

	// printf("-ex04_test_case-\n\n");
	// int nbr1 = 1530;
	// int nbr2 = -569;
	// char *base1 = "0123456789ABCDEF";
	// char *base2 = "poneyvif";
	// char *base3 = "01234567";
	// printf("input nbr : 1530 | base : 0123456789ABCDEF\n\n");
	// printf("answer : 5FA\n\n");
	// ft_putnbr_base(nbr1, base1);
	// printf("\n\ninput nbr : 1530 | base : poneyvif\n\n");
	// printf("answer : nffn\n\n");
	// ft_putnbr_base(nbr1, base2);
	// printf("\n\ninput nbr : -569 | base : 01234567\n\n");
	// printf("answer : -1071\n\n");
	// ft_putnbr_base(nbr2, base3);
	// printf("\n\n------------------------------\n\n");

	// //  // Exercise 01
	// ft_putstr("");
	// ft_putstr("Hello World!\n\n");

	// // Exercise 02
	// ft_putnbr(-2147483648);
	// write(1, "\n", 1);
	// ft_putnbr(2147483647);
	// write(1, "\n", 1);
	// ft_putnbr(0);
	// write(1, "\n", 1);
	// ft_putnbr(20230722);
	// write(1, "\n", 1);
	// ft_putnbr(-20230722);
	// write(1, "\n\n", 2);

	// // // Exercise 00
	// printf("%d ", ft_strlen(""));
	// printf("%d ", ft_strlen("Hello"));
	// printf("%d\n\n", ft_strlen("Hello World!"));
	
	// // // Exercise 03
	// printf("%d\n", ft_atoi(" ---+--+1234ab567"));
	// printf("%d\n", ft_atoi("\t\n\v\f\r +-+-1234z"));
	// printf("%d\n", ft_atoi("\t\n\v\f\r +-+--1234z"));
	// printf("%d\n", ft_atoi("\t\n\v\f\r +-+-+1234z"));
	// printf("%d\n", ft_atoi("2147483647"));
	// printf("%d\n", ft_atoi("-2147483648"));

	// // // Exercise 04
	// ft_putnbr_base(-2147483648, "0123456789");
	// write(1, "\n", 1);
	// ft_putnbr_base(2147483647, "0123456789");
	// write(1, "\n", 1);
	// ft_putnbr_base(0, "0123456789");
	// write(1, "\n", 1);
	// ft_putnbr_base(20230722, "0123456789");
	// write(1, "\n", 1);
	// ft_putnbr_base(-20230722, "0123456789");
	// write(1, "\n\n", 2);

	// ft_putnbr_base(-2147483648, "01");
	// write(1, "\n", 1);
	// ft_putnbr_base(2147483647, "01");
	// write(1, "\n", 1);
	// ft_putnbr_base(0, "01");
	// write(1, "\n", 1);
	// ft_putnbr_base(20230722, "01");
	// write(1, "\n", 1);
	// ft_putnbr_base(-20230722, "01");
	// write(1, "\n\n", 2);

	// ft_putnbr_base(-2147483648, "0123456789ABCDEF");
	// write(1, "\n", 1);
	// ft_putnbr_base(2147483647, "0123456789ABCDEF");
	// write(1, "\n", 1);
	// ft_putnbr_base(0, "0123456789ABCDEF");
	// write(1, "\n", 1);
	// ft_putnbr_base(20230722, "0123456789ABCDEF");
	// write(1, "\n", 1);
	// ft_putnbr_base(-20230722, "0123456789ABCDEF");
	// write(1, "\n\n", 2);

	// ft_putnbr_base(-2147483648, "poneyvif");
	// write(1, "\n", 1);
	// ft_putnbr_base(2147483647, "poneyvif");
	// write(1, "\n", 1);
	// ft_putnbr_base(0, "poneyvif");
	// write(1, "\n", 1);
	// ft_putnbr_base(20230722, "poneyvif");
	// write(1, "\n", 1);
	// ft_putnbr_base(-20230722, "poneyvif");
	// write(1, "\n\n", 2);

	// ft_putnbr_base(20230722, "");
	// ft_putnbr_base(20230722, "*");
	// ft_putnbr_base(20230722, "*$*");
	// ft_putnbr_base(20230722, "*$+");
	// ft_putnbr_base(20230722, "*$-");
	// ft_putnbr_base(20230722, "*$");

	// // Exercise 05
	printf("%d\n", ft_atoi_base("-2147483648", "0123456789"));
	printf("%d\n", ft_atoi_base("2147483647", "0123456789"));
	printf("%d\n", ft_atoi_base("0", "0123456789"));
	printf("%d\n", ft_atoi_base("20230722", "0123456789"));
	printf("%d\n\n", ft_atoi_base("-20230722", "0123456789"));

	printf("%d\n", ft_atoi_base("-10000000000000000000000000000000", "01"));
	printf("%d\n", ft_atoi_base("1111111111111111111111111111111", "01"));
	printf("%d\n", ft_atoi_base("0", "01"));
	printf("%d\n", ft_atoi_base("1001101001011001001000010", "01"));
	printf("%d\n\n", ft_atoi_base("-1001101001011001001000010", "01"));

	printf("%d\n", ft_atoi_base("-80000000", "0123456789ABCDEF"));
	printf("%d\n", ft_atoi_base("7FFFFFFF", "0123456789ABCDEF"));
	printf("%d\n", ft_atoi_base("0", "0123456789ABCDEF"));
	printf("%d\n", ft_atoi_base("134B242", "0123456789ABCDEF"));
	printf("%d\n\n", ft_atoi_base("-134B242", "0123456789ABCDEF"));

	printf("%d\n", ft_atoi_base("-npppppppppp", "poneyvif"));
	printf("%d\n", ft_atoi_base("offffffffff", "poneyvif"));
	printf("%d\n", ft_atoi_base("p", "poneyvif"));
	printf("%d\n", ft_atoi_base("oovoeoopn", "poneyvif"));
	printf("%d\n\n", ft_atoi_base("-oovoeoopn", "poneyvif"));

	printf("%d\n", ft_atoi_base("$**$$*$**$*$$**$**$****$*", "*$"));
	printf("%d\n", ft_atoi_base(" ---+--+1234ab567", "0123456789"));
	printf("%d\n", ft_atoi_base("\t\n\v\f\r +-+-1234z", "0123456789"));
	printf("%d\n", ft_atoi_base("\t\n\v\f\r +-+--1234z", "0123456789"));
	printf("%d\n\n", ft_atoi_base("\t\n\v\f\r +-+-+1234z", "0123456789"));

	printf("%d ", ft_atoi_base("", ""));
	printf("%d ", ft_atoi_base("*", ""));
	printf("%d ", ft_atoi_base("*$*", "*$*"));
	printf("%d ", ft_atoi_base("+$*", "$*+"));
	printf("%d ", ft_atoi_base("-$*", "$*-"));
	printf("%d ", ft_atoi_base(" $*", "$* "));
	printf("%d ", ft_atoi_base("\t$*", "$*\t"));
	printf("%d ", ft_atoi_base("\n$*", "$*\n"));
	printf("%d ", ft_atoi_base("\v$*", "$*\v"));
	printf("%d ", ft_atoi_base("\f$*", "$*\f"));
	printf("%d\n", ft_atoi_base("\r$*", "$*\r"));
	write(1, "\n", 1);
	return 0;
}
int main05()
{
	ft_putstr("---ft_iterative_factorial (-1 ~ 6)\n");
	ft_putnbr(ft_iterative_factorial(-1));
	ft_putnbr(ft_iterative_factorial(0));
	ft_putnbr(ft_iterative_factorial(1));
	ft_putnbr(ft_iterative_factorial(2));
	ft_putnbr(ft_iterative_factorial(3));
	ft_putnbr(ft_iterative_factorial(4));
	ft_putnbr(ft_iterative_factorial(5));
	ft_putnbr(ft_iterative_factorial(6));
	ft_putstr("---ft_recursive_factorial (-1 ~ 6)\n");
	ft_putnbr(ft_recursive_factorial(-1));
	ft_putnbr(ft_recursive_factorial(0));
	ft_putnbr(ft_recursive_factorial(1));
	ft_putnbr(ft_recursive_factorial(2));
	ft_putnbr(ft_recursive_factorial(3));
	ft_putnbr(ft_recursive_factorial(4));
	ft_putnbr(ft_recursive_factorial(5));
	ft_putnbr(ft_recursive_factorial(6));
	ft_putstr("---ft_iterative_power (1~5)^4,  5^(3 ~ -1)\n");
	ft_putnbr(ft_iterative_power(1, 4));
	ft_putnbr(ft_iterative_power(2, 4));
	ft_putnbr(ft_iterative_power(3, 4));
	ft_putnbr(ft_iterative_power(4, 4));
	ft_putnbr(ft_iterative_power(5, 4));
	ft_putnbr(ft_iterative_power(5, 3));
	ft_putnbr(ft_iterative_power(5, 2));
	ft_putnbr(ft_iterative_power(5, 1));
	ft_putnbr(ft_iterative_power(5, 0));
	ft_putnbr(ft_iterative_power(5, -1));
	ft_putstr("---ft_recursive_power (1~5)^4,  5^(3 ~ -1)\n");
	ft_putnbr(ft_recursive_power(1, 4));
	ft_putnbr(ft_recursive_power(2, 4));
	ft_putnbr(ft_recursive_power(3, 4));
	ft_putnbr(ft_recursive_power(4, 4));
	ft_putnbr(ft_recursive_power(5, 4));
	ft_putnbr(ft_recursive_power(5, 3));
	ft_putnbr(ft_recursive_power(5, 2));
	ft_putnbr(ft_recursive_power(5, 1));
	ft_putnbr(ft_recursive_power(5, 0));
	ft_putnbr(ft_recursive_power(5, -1));
	ft_putstr("---ft_fibonacci (-1 ~ 10)\n");
	ft_putnbr(ft_fibonacci(-1));
	ft_putnbr(ft_fibonacci(0));
	ft_putnbr(ft_fibonacci(1));
	ft_putnbr(ft_fibonacci(2));
	ft_putnbr(ft_fibonacci(3));
	ft_putnbr(ft_fibonacci(4));
	ft_putnbr(ft_fibonacci(5));
	ft_putnbr(ft_fibonacci(6));
	ft_putnbr(ft_fibonacci(7));
	ft_putnbr(ft_fibonacci(8));
	ft_putnbr(ft_fibonacci(9));
	ft_putnbr(ft_fibonacci(10));
	printf("---ft_sqrt (-4 ~ 100)\n");
	for (int i = -1000; i <= 1000; i++)
		if (ft_sqrt(i))
			printf("sqrt( %d ) = %d\n", i, ft_sqrt(i));
	printf("---ft_is_prime (-4 ~ 100)\n");
	for (int i = 0; i <= 1009; i++)
		if (ft_is_prime(i))
			printf("%d ", i);
	printf("---ft_find_next_prime\n");
	printf("next_prime( %d ) = %d\n", 106, ft_find_next_prime(106));
	printf("next_prime( %d ) = %d\n", 107, ft_find_next_prime(107));
	printf("next_prime( %d ) = %d\n", 108, ft_find_next_prime(108));
	printf("next_prime( %d ) = %d\n", 109, ft_find_next_prime(109));
	printf("next_prime( %d ) = %d\n", 110, ft_find_next_prime(110));
	printf("next_prime( %d ) = %d\n", 975, ft_find_next_prime(975));
	printf("next_prime( %d ) = %d\n", 976, ft_find_next_prime(976));
	printf("next_prime( %d ) = %d\n", 977, ft_find_next_prime(977));
	printf("next_prime( %d ) = %d\n", 978, ft_find_next_prime(978));
	return 0;
}
int main06(int argc, char **argv)
{
	argc=1;
	argv=NULL;

	//: ft_print_program_name.c
	// argc=1;
	// write(  1, argv[0], ft_strlen( argv[0] )  );
	// write(1,"\n",1);

	//: ft_print_params
	// int i;
	// i = 1;
	// while (i < argc)
	// {
	//	 write(1, argv[i], ft_strlen(argv[i]));
	//	 write(1, "\n", 1);
	//	 i++;
	// }

	//: ft_rev_params
	// int i;
	// i = argc;
	// while (i > 1)
	// {
	// 	write(1, argv[i-1], ft_strlen(argv[i-1]));
	// 	write(1,"\n",1);
	//	 i--;
	// }

	//: ft_sort_params
	// int i;
	// char *tmp;

	// int sorted;
	// sorted = 0;
	// while (!sorted) ///! 버블 정렬은 여러 차례의 비교 웨이브를 갖는다 그런데 몇번?
	// {
	// 	sorted = 1; //> 이번이 마지막 웨이브이기를 기도하며 1을 설정함
	// 	i = 1;
	// 	while (i < argc - 1) //: 한 차례의 비교 웨이브
	// 	{
	// 		if (ft_strcmp(argv[i], argv[i + 1]) > 0) //< 비교 결과가 양수이면 왼쪽값이 더 크고 사전순에서 늦음. 늦으면 바꿔 -> 빨라짐.
	// 		{
	//			 tmp = argv[i];
	//			 argv[i] = argv[i+1];
	//			 argv[i+1] = tmp;
	// 			sorted = 0;
	// 			/// 이번 웨이브에서 스왑했다면, 배열이 정렬되지 않았을 수 있다
	// 			/// sorted를 0으로 넘기므로써, 다음 웨이브를 예약
	// 		}
	// 		i++;
	// 	}
	// }
	// i = 1;
	// while (i < argc)
	// {
	//	 write(1, argv[i], ft_strlen(argv[i]));
	//	 write(1, "\n", 1);
	//	 i++;
	// }
	return 0;
}
int main07()
{
	return 0;
}
int main08()
{
	return 0;
}
int main09()
{
	return 0;
}
int main10()
{
	return 0;
}
int main11()
{
	return 0;
}
int mainss()
{
	print_combn(3);
}