#include <unistd.h>
#include "../rendu/c00/ex00/ft_putchar.c"
#include "../rendu/c00/ex01/ft_print_alphabet.c"
#include "../rendu/c00/ex02/ft_print_reverse_alphabet.c"
#include "../rendu/c00/ex03/ft_print_numbers.c"
#include "../rendu/c00/ex04/ft_is_negative.c"
#include "../rendu/c00/ex05/ft_print_comb.c"
#include "../rendu/c00/ex06/ft_print_comb2.c"
#include "../rendu/c00/ex07/ft_putnbr.c"
#include "../rendu/c00/ex08/ft_print_combn.c"

int main(){
	{//: ft_purchar
		write(1,"< ft_putchar >",15);
		for (int i=32; i<=127; i++)
		{
			if ((i-32) % 9 == 0)
				ft_putchar('\n');
			ft_putchar(i);
		}
	}
	{//: ft_pirnt_alpharbet
		write(1,"\n\n< ft_pirnt_alpharbet >\n",25);
		ft_print_alphabet();
	}
	{//: ft_pirnt_reverse_alpharbet
		write(1,"\n\n< ft_pirnt_reverse_alpharbet >\n",33);
		ft_print_reverse_alphabet();
	}
	{//: ft_print_numbers
		write(1,"\n\n< ft_print_numbers >\n",23);
		ft_print_numbers();
	}
	{//: ft_is_negative
		write(1,"\n\n< ft_is_negative >\n",21);
		write(1,"requires N:\t",12);
		ft_is_negative(-2147483648);
		ft_is_negative(-2147483647);
		ft_is_negative(-1234);
		ft_is_negative(-2);
		ft_is_negative(-1);
		write(1,"\nrequires P:\t",13);
		ft_is_negative(-0);
		ft_is_negative(0);
		ft_is_negative(1);
		ft_is_negative(2);
		ft_is_negative(1234);
		ft_is_negative(2147483646);
		ft_is_negative(2147483647);
	}
	{//: ft_print_comb
		write(1,"\n\n< ft_print_comb >\n",20);
		ft_print_comb();
	}
	{//: ft_print_comb2
		write(1,"\n\n< ft_print_comb2 >\n",21);
		ft_print_comb2();	
	}
	{//: ft_putnbr
		write(1,"\n\n< ft_putnbr >\n",16);
		ft_putnbr(777);	
	}
	{//: ft_print_combn
		write(1,"\n\n< ft_print_combn >\n",21);
		ft_print_combn(7);
	}
}