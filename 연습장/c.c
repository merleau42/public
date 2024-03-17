#include <stdio.h>
#include <string.h>

typedef struct A_{
	int a;
	int b;
} A;

int main() {
	A w;
	w.a = 1;
	w.b = 2;
	printf("%d, %d", w.a, w.b);
}
