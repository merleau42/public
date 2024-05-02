#include <stdio.h>
#include <stdlib.h>

char **free_log;

void smart_free(void* any)
{
	size_t i = 1;

	free_log[0]++;
	free_log[(size_t) free_log[0]] = (char*) any;
	free(any);
}

int main()
{
	free_log = (char **) malloc(1000 * sizeof(char*));

	int *m, *n, *k;
	m = (int *) malloc(5 * sizeof(int));
	n = (int *) malloc(12 * sizeof(int));
	k = (int *) malloc(9 * sizeof(int));

	// smart_free(m);
	// smart_free(n);
	// smart_free(k);

	// size_t i = 1;
	// while(i <= (size_t) free_log[0])
	// 	printf("%p\n", free_log[i++]);

	free(m);
	free(n);
	free(m);
}

