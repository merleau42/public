#include <stdio.h>

int main()
{
	const char *base[3] = {"123", "456", "789"};
	printf("%s", base[0]);
	printf("%s", base[1]);
	printf("%s", base[2]);
}