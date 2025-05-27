#include <stdio.h>
#include <string.h>

int main() {
	//int *p;
	int p;
	
	//p = (long long *)7788;
	p = (long long)7789;

	printf("%p\n", p);
	printf("%d\n", p);
	printf("%i\n", p);
	printf("%u\n", p);
	printf("%x\n", p);
	printf("%X\n", p);
	printf("%c\n", p);
	printf("%s\n", p);	
}

