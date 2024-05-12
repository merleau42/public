#include <stdio.h>

int 반복문중첩()
{
	int i, mini, maxi;
	int j, minj, maxj;
	int row, col;
	int a, b;

	scanf("%d", &a);

	i = mini;
	while (i <= maxi)
	{
		j = minj;
		while (j <= maxj)
		{
			printf("%d * %d = %d\n", i, j, i*j); // 구구단
			printf("*"); // 별찍기
			j++;
		}
		// printf("\n");
		i++;
	}
}

int 비교연산()
{
	int a, b;
	scanf("%d %d", &a, &b);
	
	if (a > b)
		printf(">");
	if (a == b)
		printf("==");
	if (a < b)
		printf("<");
}

int 사칙연산()
{
	int a, b;
	scanf("%d %d", &a, &b);

	printf("%d\n", a + b);
	printf("%d\n", a - b);
	printf("%d\n", a * b);
	printf("%d\n", a / b);
	printf("%d", a % b);
}

int 정밀도()
{
	int a,b;
	scanf("%d %d", &a, &b);
	printf("%.10f", (double)a / b);
}

int 정수론()
{
	int year;
	scanf("%d", &year);
	
	// 윤년은 연도가 4의 배수이면서, 100의 배수가 아닐 때 또는 400의 배수일 때이다.
	if (year % 4 == 0 && ( year % 100 != 0 || year % 400 == 0 ))
		printf("1");
	else 
		printf("0");
}

void 조건분기()
{
	int a;
	scanf("%d", &a);
	
	if (90 <= a && a <= 100)
		printf("A");
	else if (80 <= a && a <= 89)
		printf("B");
	else if (70 <= a && a <= 79)
		printf("C");
	else if (60 <= a && a <= 69)
		printf("D");
	else 
		printf("F");
}

void 단순출력()
{
	// 고양이
	printf("\\    /\\\n )  ( ')\n(  /  )\n \\(__)|");

	// 강아지1
	printf("|\\_/|\n|q p|   /}\n( 0 )\"\"\"\\\n|\"^\"`    |\n||_/=\\\\__|");

	// 강아지2
	printf("|\\_/|\n");
	printf("|q p|   /}\n");
	printf("( 0 )\"\"\"\\\n");
	printf("|\"^\"`    |\n");
	printf("||_/=\\\\__|\n");
}