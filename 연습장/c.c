#include <stdio.h>
#include <string.h>

int main() {
	printf("%p	\n", (void*) 0);
	printf("%p	\n", (void*) 1);
	printf("%p	\n", (void*) 2);
	printf("%p	\n", (void*) 3);

	printf("%p	\n", (int*) 0);
	printf("%p	\n", (int*) 1);
	printf("%p	\n", (int*) 2);
	printf("%p	\n", (int*) 3);
}
