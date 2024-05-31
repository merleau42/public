#include <stdio.h>
#include <stdlib.h>

int main()
{
	unsigned long long color;
	color = 0x11223344;

	printf("%.8llx\n", color);
	printf("%.8llx\n", color>>8);
	printf("%.8llx\n", color>>16);
	printf("%.8llx\n", color>>24);

	printf("%f\n", 7 / (float)2);
}


// 시작색 + (도달색 - 시작색) * 비율
// ㄴ 비율0 == 시작색
// ㄴ 비율1 == 도달색