#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "단권화.c"
void testcase00();
void testcase01();
void testcase02();
void testcase03();
void testcase04();
void testcase04_v2();
void testcase05();
void testcase07();

//	예쁜 색깔 넣기 (%s ~ %s)
char *color;
char *DEFAULT = "\033[0;00m";
char *RED = "\033[0;31m";
char *YELLOW = "\033[0;32m";
char *GREEN = "\033[0;36m";
char *BLUE = "\033[0;34m";
char *PINK = "\033[0;35m";

// 연습장
int main_(){
	char *w;
	printf("%s ----> %s", (w = "hello world !!", w), ft_split(w, " "));
}

//	테케 불러오기
int main(){  ft_putnbr(ft_ten_queens_puzzle()); }

//	argc, argv 연습장
int main0(int argc, char **argv) //c06 ex00
{
	int i;

	(void) argc;
	i = 0;
	while(argv[0][i] != '\0')
	{
		write(1, &argv[0][i], 1);
		i++;
	}
	write(1,"\n",1);
	return 0;
}
int main1(int argc, char **argv) //c06 ex01
{
	int i;
	int argn;

	argn = 1;
	while(argn <= argc - 1)
	{
		i = 0;
		while(argv[argn][i] != '\0')
		{
			write(1, &argv[argn][i], 1);
			i++;
		}
		write(1,"\n",1);
		argn++;
	}
	return 0;
}
int main2(int argc, char **argv) //c06 ex02
{
	int i;
	int argn;

	argn = argc - 1;
	while(argn >= 1)
	{
		i = 0;
		while(argv[argn][i] != '\0')
		{
			write(1, &argv[argn][i], 1);
			i++;
		}
		write(1,"\n",1);
		argn--;
	}
	return 0;
}
int main3(int argc, char **argv) //c06 ex03
{
	int argn;
	int sorted;
	char *tmp;

	sorted = 0;
	while (sorted == 0)
	{
		sorted = 1;
		argn = 2;
		while (argn <= argc - 1)
		{
			if (ft_strcmp(argv[argn-1], argv[argn]) > 0)
			{
				tmp = argv[argn];
				argv[argn] = argv[argn-1];
				argv[argn-1] = tmp;
				sorted = 0;
			}
			argn++;
		}
	}
	ft_print_params(argc, argv);
	return 0;
}

//  테케 보관함
void template(){
	{//: ft_
	write(1,YELLOW,7);
	write(1,"\n\n< ft_ >\n",23);
	write(1,DEFAULT,7);
	// ft_();
	}
}
void testcase03(){
	//	문자열 셋팅
	char *a[99] = {"dragon", "d", "dragon", "dragon", "dragon", "dragonball", "dragonfly", "dragonball", "dragonfall", "dragon", "dream", "ball", "fall", "dragon", "d", "\0", "\0", "\0"};
	char *b[99] = {"dragon", "dragon", "dragonball", "dragonfly", "d", "dragon", "dragon", "dragonfall", "dragonball", "dream", "dragon", "fall", "ball", "\0", "\0", "dragon", "d", "\0"};

	// strcmp
	for (int i=0; a[i]!=0; i++)
	{
		int left  = strcmp(a[i], b[i]);
		int right = ft_strcmp(a[i], b[i]);

		color = (left == right) ? GREEN : RED;

		printf("%s\n\"%s\"\n\"%s\"%s\n", YELLOW, a[i], b[i], DEFAULT);
		printf("strcmp\t\tft\n");

		printf("%s%d\t\t%d%s\n", color, left, right, DEFAULT);
	}
	printf("\n\n\n-------------------------");

	// strNcmp
	for (int i=0; a[i]!=0; i++){
		printf("%s\n\"%s\"\n\"%s\"%s\n", YELLOW, a[i], b[i], DEFAULT);
		printf("N:\tstrncmp\t\tft\n");

		for (int n=-2; n<=13; n++)
		{
			int left  = strncmp(a[i], b[i], n);
			int right = ft_strncmp(a[i], b[i], n);

			if (left != right)
				printf("%s%d:\t%d\t\t%d%s\n", RED, n, left, right, DEFAULT);
		}
	}

	// strcat

}
void testcase04(){
	char *s;

	printf("---------- ft_atoi -----------\n");
	printf("TEST: %s  --->  %d\n", s="", ft_atoi(s));
	printf("TEST: %s  --->  %d\n", s="a", ft_atoi(s));
	printf("TEST: %s  --->  %d\n", s="-a", ft_atoi(s));
	printf("TEST: %s  --->  %d\n", s="    ", ft_atoi(s));
	printf("TEST: %s  --->  %d\n", s="12345aaa777", ft_atoi(s));
	printf("TEST: %s  --->  %d\n", s="12345   777", ft_atoi(s));
	printf("TEST: %s  --->  %d\n", s="12345a a777", ft_atoi(s));
	printf("TEST: %s  --->  %d\n", s="012345aaa777", ft_atoi(s));
	printf("TEST: %s  --->  %d\n", s="000012345aaa777", ft_atoi(s));
	printf("TEST: %s  --->  %d\n", s="      000012345aaa777", ft_atoi(s));
	printf("TEST: %s  --->  %d\n", s="      +000012345aaa777", ft_atoi(s));
	printf("TEST: %s  --->  %d\n", s="      ++000012345aaa777", ft_atoi(s));
	printf("TEST: %s  --->  %d\n", s="      +++000012345aaa777", ft_atoi(s));
	printf("TEST: %s  --->  %d\n", s="      +++-000012345aaa777", ft_atoi(s));
	printf("TEST: %s  --->  %d\n", s="      +++--000012345aaa777", ft_atoi(s));
	printf("TEST: %s  --->  %d\n", s="      +++---000012345aaa777", ft_atoi(s));
	printf("TEST: %s  --->  %d\n", s="      +-++--000012345aaa777", ft_atoi(s));
	printf("TEST: %s  --->  %d\n", s="      +-++--++000012345aaa777", ft_atoi(s));
	printf("TEST: %s  --->  %d\n", s="      +-++--++00000aaa777", ft_atoi(s));
	printf("TEST: %s  --->  %d\n", s="      ++++--++000002147483646aaa777", ft_atoi(s));
	printf("TEST: %s  --->  %d\n", s="      ++++--++000002147483647aaa777", ft_atoi(s));
	printf("TEST: %s  --->  %d\n", s="      +-++--++000002147483647aaa777", ft_atoi(s));
	printf("TEST: %s  --->  %d\n", s="      +-++--++000002147483648aaa777", ft_atoi(s));
	printf("EDGE: %s  --->  %d vs %d (man atoi)\n", s="2147483646aaa777", ft_atoi(s), atoi(s));
	printf("EDGE: %s  --->  %d vs %d (man atoi)\n", s="2147483647aaa777", ft_atoi(s), atoi(s));
	printf("EDGE: %s  --->  %d vs %d (man atoi)\n", s="2147483648aaa777", ft_atoi(s), atoi(s));
	printf("EDGE: %s  --->  %d vs %d (man atoi)\n", s="2147483649aaa777", ft_atoi(s), atoi(s));
	printf("EDGE: %s  --->  %d vs %d (man atoi)\n", s="-2147483646aaa777", ft_atoi(s), atoi(s));
	printf("EDGE: %s  --->  %d vs %d (man atoi)\n", s="-2147483647aaa777", ft_atoi(s), atoi(s));
	printf("EDGE: %s  --->  %d vs %d (man atoi)\n", s="-2147483648aaa777", ft_atoi(s), atoi(s));
	printf("EDGE: %s  --->  %d vs %d (man atoi)\n", s="-2147483649aaa777", ft_atoi(s), atoi(s));
	printf("INVALID: %s  --->  %d\n", s="  +    +-++--++000012345aaa777", ft_atoi(s));
	printf("INVALID: %s  --->  %d\n", s="  -    +-++--++000012345aaa777", ft_atoi(s));
	printf("INVALID:  %s  --->  %d\n", s="as      +-++--++000012345aaa777", ft_atoi(s));
	printf("INVALID: %s  --->  %d\n", s="    as      +-++--++000012345aaa777", ft_atoi(s));
}
void testcase04_v2(){
	setbuf(stdout, NULL);

	printf("========== ex00 ==========\n");

	char	*str001 = "1234567890";

	printf("str1 : %s | origin strlen : %lu | ft_strlen : %d\n", str001, strlen(str001), ft_strlen(str001));

	printf("========== ex01 ==========\n");

	char	*str011 = "ABCDE";
	char	*str012 = "ABCDEFG";

	printf("origin : %s | %s\n", str011, str012);
	ft_putstr(str011);
	ft_putstr("\n");
	ft_putstr(str012);
	ft_putstr("\n");

	printf("========== ex02 ==========\n");

	int		num021 = 42;
	int		num022 = -42;
	int		num023 = 0;
	int		num024 = -2147483648;

	printf("num list : %d | %d | %d | %d\n", num021, num022, num023, num024);
	ft_putnbr(num021);
	ft_putstr("\n");
	ft_putnbr(num022);
	ft_putstr("\n");
	ft_putnbr(num023);
	ft_putstr("\n");
	ft_putnbr(num024);
	ft_putstr("\n");

	printf("========== ex03 ft_atoi ==========\n");

	char	*str031 = "  ---+--+1234ab567";
	char	*str032 = "\t\t--+-+-19403+asd3";
	char	*str033 = "\r --+---0+asdwasd3";
	char	*str034 = " \r--+-+++2147483648asdwasd3";

	printf("str1 : %s | result : %d\n", str031, ft_atoi(str031));
	printf("str2 : %s | result : %d\n", str032, ft_atoi(str032));
	printf("str3 : %s | result : %d\n", str033, ft_atoi(str033));
	printf("str4 : %s | result : %d\n", str034, ft_atoi(str034));

	printf("========== ex04 ft_putnbr_base ==========\n");

	int		num041 = 123456789;
	char	*str041 = "ABCDEFGHIJ\0";
	int		num042 = -256;
	char	*str042 = "01234567\0";
	int		num043 = 0;
	char	*str043 = "ABCA\0";
	int		num044 = -2147483648;
	char	*str044 = "0123456789\0";
	int		num045 = 19711121;
	char	*str045 = "0123456789ABCDEF\0";
	int		num046 = 19711121;
	char	*str046 = "0123456789ABCDEF+\0";

	printf("num1 : %d | str1 : %s\nresult : ", num041, str041);
	ft_putnbr_base(num041, str041);
	printf("\n-----\n");
	printf("num2 : %d | str2 : %s\nresult : ", num042, str042);
	ft_putnbr_base(num042, str042);
	printf("\n-----\n");
	printf("num3 : %d | str3 : %s\nresult : ", num043, str043);
	ft_putnbr_base(num043, str043);
	printf("\n-----\n");
	printf("num4 : %d | str4 : %s\nresult : ", num044, str044);
	ft_putnbr_base(num044, str044);
	printf("\n-----\n");
	printf("num5 : %d | str5 : %s\nresult : ", num045, str045);
	ft_putnbr_base(num045, str045);
	printf("\n-----\n");
	printf("num6 : %d | str6 : %s\nresult : ", num046, str046);
	ft_putnbr_base(num046, str046);
	ft_putstr("\n");

	printf("========== ex05 ft_atoi_base ==========\n");

	char	*num051 = " -2147483648\0";
	char	*str051 = "0123456789\0";
	char	*num052 = " \t--+--400dfse\0";
	char	*str052 = "01234567\0";
	char	*num053 = " \t--+--400dfse";
	char	*str053 = "012345670\0";
	char	*num054 = " \t--+--400dfse";
	char	*str054 = "01234567-\0";
	char	*num055 = "  \r\t --+-++--cBeHeiDgei";
	char	*str055 = "aBcDeFgHiG\0"; 

	printf("num1 : %s | str1 : %s\nresult : %d\n",
			num051, str051, ft_atoi_base(num051, str051));
	printf("\n-----\n");
	printf("num2 : %s | str2 : %s\nresult : %d\n",
			num052, str052, ft_atoi_base(num052, str052));
	printf("\n-----\n");
	printf("num3 : %s | str3 : %s\nresult : %d\n",
			num053, str053, ft_atoi_base(num053, str053));
	printf("\n-----\n");
	printf("num4 : %s | str4 : %s\nresult : %d\n",
			num054, str054, ft_atoi_base(num054, str054));
	printf("\n-----\n");
	printf("num3 : %s | str3 : %s\nresult : %d\n",
			num055, str055, ft_atoi_base(num055, str055));
}
void testcase05(){
    // Testing ft_iterative_factorial
    printf("===Testing ft_iterative_factorial===\n");
    printf("Iterative Factorial of 5: %d\n", ft_iterative_factorial(5));
    printf("Iterative Factorial of 0: %d\n", ft_iterative_factorial(0));
    printf("Iterative Factorial of -3: %d\n", ft_iterative_factorial(-3));

    // Testing ft_recursive_factorial
    printf("\n===Testing ft_recursive_factorial===\n");
    printf("Recursive Factorial of 5: %d\n", ft_recursive_factorial(5));
    printf("Recursive Factorial of 0: %d\n", ft_recursive_factorial(0));
    printf("Recursive Factorial of -3: %d\n", ft_recursive_factorial(-3));

    // Testing ft_iterative_power
    printf("\n===Testing ft_iterative_power===\n");
    printf("Iterative Power 2^3: %d\n", ft_iterative_power(2, 3));
    printf("Iterative Power 2^0: %d\n", ft_iterative_power(2, 0));
    printf("Iterative Power 2^-2: %d\n", ft_iterative_power(2, -2));

    // Testing ft_recursive_power
    printf("\n===Testing ft_recursive_power===\n");
    printf("Recursive Power 2^3: %d\n", ft_recursive_power(2, 3));
    printf("Recursive Power 2^0: %d\n", ft_recursive_power(2, 0));
    printf("Recursive Power 2^-2: %d\n", ft_recursive_power(2, -2));

    // Testing ft_fibonacci
    printf("\n===Testing ft_fibonacci===\n");
    printf("Fibonacci of 5: %d\n", ft_fibonacci(5));
    printf("Fibonacci of 10: %d\n", ft_fibonacci(10));
    printf("Fibonacci of 15: %d\n", ft_fibonacci(15));
    printf("Fibonacci of -1: %d\n", ft_fibonacci(-1));

    // Testing ft_sqrt
    printf("\n===Testing ft_sqrt===\n");
    printf("Square root of 16: %d\n", ft_sqrt(16));
    printf("Square root of 10: %d\n", ft_sqrt(10));
    printf("Square root of 4: %d\n", ft_sqrt(4));
    printf("Square root of 25: %d\n", ft_sqrt(25));
    printf("Square root of 2147395600: %d\n", ft_sqrt(2147395600));
    printf("Square root of 1: %d\n", ft_sqrt(1));
    printf("Square root of -4: %d\n", ft_sqrt(-4));

    // Testing ft_is_prime
    printf("\n===Testing ft_is_prime===\n");
    printf("Is 5 prime: %d\n", ft_is_prime(5));
    printf("Is 4 prime: %d\n", ft_is_prime(4));
    printf("Is 2147483647 prime: %d\n", ft_is_prime(2147483647));
    printf("Is 1 prime: %d\n", ft_is_prime(1));
    printf("Is -3 prime: %d\n", ft_is_prime(-3));

    // Testing ft_find_next_prime
    printf("\n===Testing ft_find_next_prime===\n");
    printf("Next prime after 10: %d\n", ft_find_next_prime(10));
    printf("Next prime after 21: %d\n", ft_find_next_prime(29));
    printf("Next prime after 17: %d\n", ft_find_next_prime(17));
    printf("Next prime after -5: %d\n", ft_find_next_prime(-5));
    printf("Next prime after 1: %d\n", ft_find_next_prime(1));
    printf("Next prime after 0: %d\n", ft_find_next_prime(0));

    // Testing ft_ten_queens_puzzle
    printf("\n===Testing ft_tens_queens_puzzle===\n");
    printf("Number of solutions for the Ten Queens Puzzle: %d\n", ft_ten_queens_puzzle());
}
void testcase07(){;}
