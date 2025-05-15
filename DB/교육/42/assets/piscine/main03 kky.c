#include <stdio.h>
#include <string.h>
#include "../rendu/c03/ex00/ft_strcmp.c"
#include "../rendu/c03/ex01/ft_strncmp.c"
#include "../rendu/c03/ex02/ft_strcat.c"
#include "../rendu/c03/ex03/ft_strncat.c"
#include "../rendu/c03/ex04/ft_strstr.c"
#include "../rendu/c03/ex05/ft_strlcat.c"

//	예쁜 색깔 넣기 (%s ~ %s)
char *color;
char *DEFAULT = "\033[0;00m";
char *RED = "\033[0;31m";
char *YELLOW = "\033[0;32m";
char *GREEN = "\033[0;36m";
char *BLUE = "\033[0;34m";
char *PINK = "\033[0;35m";

int main(){
	//	문자열 셋팅
	char *a[99] = {"dragon", "d", "dragon", "dragon", "dragon", "dragonball", "dragonfly", "dragonball", "dragonfall", "dragon", "dream", "ball", "fall", "dragon", "d", "\0", "\0", "\0"};
	char *b[99] = {"dragon", "dragon", "dragonball", "dragonfly", "d", "dragon", "dragon", "dragonfall", "dragonball", "dream", "dragon", "fall", "ball", "\0", "\0", "dragon", "d", "\0"};

	// strcmp
	for (int i=0; a[i]!=0; i++)
	{
		int left  = strcmp(a[i], b[i]);
		int right = ft_strcmp(a[i], b[i]);

		color = (left == right) ? GREEN : RED;

		printf("%s\n\"%s\"\n\"%s\"%s\n", YELLOW, a[i], b[i], DEFAULT);
		printf("strcmp\t\tft\n");

		printf("%s%d\t\t%d%s\n", color, left, right, DEFAULT);
	}
	printf("\n\n\n-------------------------");

	// strNcmp
	for (int i=0; a[i]!=0; i++){
		printf("%s\n\"%s\"\n\"%s\"%s\n", YELLOW, a[i], b[i], DEFAULT);
		printf("N:\tstrncmp\t\tft\n");

		for (int n=-2; n<=13; n++)
		{
			int left  = strncmp(a[i], b[i], n);
			int right = ft_strncmp(a[i], b[i], n);

			if (left != right)
				printf("%s%d:\t%d\t\t%d%s\n", RED, n, left, right, DEFAULT);
		}
	}

	// strcat

}