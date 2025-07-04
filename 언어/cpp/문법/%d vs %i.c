#include <stdio.h>
#include <string.h>

int main() {
	FILE *f1 = fopen("/home/keunykim/dev/연습장/f1", "w");
	FILE *f2 = fopen("/home/keunykim/dev/연습장/f2", "w");

	for (int i=-1000000; i <= 0; i++)
	{
		fprintf(f1, "%d", i);
		fprintf(f2, "%i", i);
	}
}
