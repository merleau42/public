// 첫째 줄에는 별 1개, 둘째 줄에는 별 2개, N번째 줄에는 별 N개를 찍는 문제

#include <stdio.h>

int main()
{
	int row, col;
	int a, b;

	scanf("%d", &a);

	row = 1;
	while (row <= a)
	{
		col = 1;
		while (col <= row)
		{
			printf("*");
			col++;
		}
		printf("\n");
		row++;
	}
}