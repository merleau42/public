#include <stdio.h>
#include <string.h>

int main() {
	void		*v;
    char		*c;
	int			*i;
	long long	*ll;
	size_t		*s;

    char		plus_c;
	int			plus_i;
	long long	plus_ll;
	size_t		plus_s;

	plus_c = 2;
	plus_i = 2;
	plus_ll = 2;
	plus_s = 2;

	printf("(void*)v - 2		%p\n",	 v-2);
	printf("(void*)v - 1		%p\n",	 v-1);
	printf("(void*)v    		%p\n",	 v);
	printf("(void*)v + 1		%p\n",	 v+1);
	printf("(void*)v + literal 2	%p\n",	 v+2);
	printf("(void*)v + char 2	%p\n", v + plus_c);
	printf("(void*)v + int 2	%p\n", v + plus_i);
	printf("(void*)v + ll 2		%p\n", v + plus_ll);
	printf("(void*)v + size_t 2	%p\n\n", v + plus_s);

	printf("(char*)c - 2		%p\n",	 c-2);
	printf("(char*)c - 1		%p\n",	 c-1);
	printf("(char*)c 		%p\n",	 c);
	printf("(char*)c + 1		%p\n",	 c+1);
	printf("(char*)c + literal 2	%p\n",   c+2);
	printf("(char*)c + char 2	%p\n", c + plus_c);
	printf("(char*)c + int 2	%p\n", c + plus_i);
	printf("(char*)c + ll 2		%p\n", c + plus_ll);
	printf("(char*)c + size_t 2	%p\n\n", c + plus_s);

	printf("(int*)i - 2		%p\n",	 i-2);
	printf("(int*)i - 1		%p\n",	 i-1);
	printf("(int*)i 		%p\n",	 i);
	printf("(int*)i + 1		%p\n",	 i+1);
	printf("(int*)i + literal 2	%p\n",   i+2);
	printf("(int*)i + char 2	%p\n", i + plus_c);
	printf("(int*)i + int 2		%p\n", i + plus_i);
	printf("(int*)i + ll 2		%p\n", i + plus_ll);
	printf("(int*)i + size_t 2	%p\n\n", i + plus_s);

	printf("(long long*)L - 2		%p\n",	 ll-2);
	printf("(long long*)L - 1		%p\n",	 ll-1);
	printf("(long long*)L 			%p\n",	 ll);
	printf("(long long*)L + 1		%p\n",	 ll+1);
	printf("(long long*)L + literal 2	%p\n", 	 ll+2);
	printf("(long long*)L + char 2		%p\n", ll + plus_c);
	printf("(long long*)L + int 2		%p\n", ll + plus_i);
	printf("(long long*)L + ll 2		%p\n", ll + plus_ll);
	printf("(long long*)L + size_t 2	%p\n\n", ll + plus_s);

	printf("(size_t*)S - 2		%p\n",	 s-2);
	printf("(size_t*)S - 1		%p\n",	 s-1);
	printf("(size_t*)S 		%p\n",	 s);
	printf("(size_t*)S + 1		%p\n",	 s+1);
	printf("(size_t*)S + literal 2	%p\n",   s+2);
	printf("(size_t*)S + char 2	%p\n", s + plus_c);
	printf("(size_t*)S + int 2	%p\n", s + plus_i);
	printf("(size_t*)S + ll 2	%p\n", s + plus_ll);
	printf("(size_t*)S + size_t 2	%p\n\n", s + plus_s);
}
