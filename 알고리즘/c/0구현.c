#include <unistd.h>
// 출력 ㅡ write

#include <stdio.h>
// 출력 ㅡ printf
// 입력 ㅡ scanf

#include <stdlib.h>
// 변환 ㅡ atoi, itoa
// 할당 ㅡ malloc, calloc

#include <string.h>
// 대입 ㅡ memset, bzero
// 탐색 ㅡ strlen, strchr, strrchr, memchr, strstr
// 비교 ㅡ strncmp, memcmp
// 복제 ㅡ strdup, memmove, strlcpy, strlcat

//: 전역 변수는 0으로 초기화 됨.
size_t T, t; // 테스트 케이스
char **parsed;
char str[1000000]; int len;
char str1[1000000]; int len1;
char str2[1000000]; int len2;
char exist[256];
int count;
int sum;
void *rewind_;
int seri[1000000];
char *entered[1000000];
char enter;
int a, b;
int n, m;
int i, j, k;
int r, c, h;
int x, y, z;
int scanned;

void 중첩반복문()
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

void 사칙연산()
{
	int a, b;
	scanf("%d %d", &a, &b);

	printf("%d\n", a + b);
	printf("%d\n", a - b);
	printf("%d\n", a * b);
	printf("%d\n", a / b);
	printf("%d", a % b);
}

void 정밀도()
{
	int a,b;
	scanf("%d %d", &a, &b);
	printf("%.10f", (double)a / b);
}

void 정수론()
{
	int year;
	scanf("%d", &year);
	
	// 윤년은 연도가 4의 배수이면서, 100의 배수가 아닐 때 또는 400의 배수일 때이다.
	if (year % 4 == 0 && ( year % 100 != 0 || year % 400 == 0 ))
		printf("1");
	else 
		printf("0");
}

void 비교()
{
	if (90 <= a && a <= 100)		printf("A");
	else if (80 <= a && a <= 89)	printf("B");
	else if (70 <= a && a <= 79)	printf("C");
	else if (60 <= a && a <= 69)	printf("D");
	else 							printf("F");

	if (a > b)		printf(">");
	if (a == b)		printf("==");
	if (a < b)		printf("<");
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

void 수열()
{
	if (m < x)
	printf("%d ", x)
	;
}

int main() {
	// T = 테스트 케이스의 유형 (자료형 size_t)
	// -1: 사실상 무한대, 종료 신호까지  /  0: 스킵
	//  1: 한 줄의 입력만 주어짐  /  2: 입력 횟수가 주어짐
	
	// (r,c,h) (n,m,k) (x,y,z) 등 주어지는 경우 앞에서 받음.
	// 비교 문자열이 주어지면, str1 str2로 쓰고 str로 복원하기.
	scanf("%d %d", &n, &m); getchar();
	// scanf("%s", str1); getchar();

	T = -1;
	if (T == 2)	{
		scanf("%zd", &T);
		getchar();
	}
	for (size_t t=1; t <= T; t++) {
		if (t > 1) getchar();

		//: 테스트 케이스를 공백으로 구분하는 경우
		scanned = scanf("%d", &x);
		if (scanned == EOF || x != 'sign')
			break;
		
		//: 테스트 케이스를 라인으로 구분하는 경우
		// scanned = scanf("%[^\n]s", str);
		// if (scanned == EOF || strcmp(str, "종료신호") == 0)
			// break;
		
		//: 입력 받아서 실행할 내용
		수열();
		// printf("%d. %s\n", t, str);
	}
	// printf("%d", count);

	if (r > 0 && c > 0) { // 행렬이 주어짐
		for (int i = 1; i <= r; i++) {
			if (i > 1) getchar();
			scanf("%[^\n]s", str);
			비교();
			// for (int j = 1; i <= c; j++){
			// 	;
			// }
		}
	}
}