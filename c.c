#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	size_t a;
	a = 0;
	char *s="aqwec";

	printf("%c", s[a++]);
	printf("%c", s[a++]);
	printf("%c", s[a++]);
}
