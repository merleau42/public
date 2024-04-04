#include <stdio.h>
#include <string.h>

int main()
{
	char *a[4];

	a[0] = strdup("abc");
	a[1] = strdup("def");
	a[2] = strdup("ghi");
	a[3] = (void *) 0;
	printf("%s", a[0]);
	printf("%s", a[1]);
	printf("%s", a[2]);
	printf("%s", a[3]);
}