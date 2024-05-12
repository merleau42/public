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
char *words[10000];
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
char ch;

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
	int i;
	i = 0;
	while (i < x/4)
	{
		printf("long ");
		i++;
	}
	printf("int");
}

void 정밀도()
{
	printf("%.10f", (double)a / b);
}

void 정수론()
{
	// 윤년은 연도가 4의 배수이면서, 100의 배수가 아닐 때 또는 400의 배수일 때이다.
	if (y % 4 == 0 && ( y % 100 != 0 || y % 400 == 0 ))
		printf("1");
	else 
		printf("0");
}

void 비교()
{
	if (n == m)
		printf("1");
	else
		printf("0");
}

void 수열순회()
{
	int i;

	i = 0;
	while(i < T)
	{
		if (seri[i] == x)
			count++;
		i++;
	}
	
	printf("%d", count);
}

void 서식()
{
	//: char 변수를 %d로 출력
	// printf("%d", ch);


	//: 팬들에게 둘러쌓인 홍준
	// char *fan;
	// fan = ":fan:";
	// printf("%s%s%s\n%s:%s:%s\n%s%s%s",fan,fan,fan,fan,str1,fan,fan,fan,fan);
	printf(":fan::fan::fan:\n:fan::%s::fan:\n:fan::fan::fan:",str1);
}

void 케이스()
{
	if (n == 0)
		printf("YONSEI");
	if (n == 1)
		printf("Leading the Way to the Future");
}

void 단순출력()
{
	//: 강아지2
	// printf("|\\_/|\n");
	// printf("|q p|   /}\n");
	// printf("( 0 )\"\"\"\\\n");
	// printf("|\"^\"`    |\n");
	// printf("||_/=\\\\__|\n");

	//: 새싹
	// printf("         ,r'\"7\n");
	// printf("r`-_   ,'  ,/\n");
	// printf(" \\. \". L_r'\n");
	// printf("   `~\\/\n");
	// printf("      |\n");
	// printf("      |");

	//: 분해해서 출력
	// words[1] = "       ";
	// words[2] = "_.-;;-._";
	// words[3] = "'-..-'";
	// words[4] = "|   ||   |";
	// words[5] = "|_.-;;-._|";
	// words[6] = "|_.-''-._|";

	// printf("%s%s\n%s%s\n%s%s\n%s%s\n%s%s",
	// 	words[1], words[2], words[3], words[4], words[3], words[5], words[3], words[4], words[3], words[6]);

	//: 스타워즈
	// printf("    8888888888  888    88888\n");
	// printf("   88     88   88 88   88  88\n");
	// printf("    8888  88  88   88  88888\n");
	// printf("       88 88 888888888 88   88\n");
	// printf("88888888  88 88     88 88    888888\n\n");
	// printf("88  88  88   888    88888    888888\n");
	// printf("88  88  88  88 88   88  88  88\n");
	// printf("88 8888 88 88   88  88888    8888\n");
	// printf(" 888  888 888888888 88  88      88\n");
	// printf("  88  88  88     88 88   88888888");

	//: 콜센터
	// printf("     /~\\\n");
	// printf("    ( oo|\n");
	// printf("    _\\=/_\n");
	// printf("   /  _  \\\n");
	// printf("  //|/.\\|\\\\\n");
	// printf(" ||  \\ /  ||\n");
	// printf("============\n");
	// printf("|          |\n");
	// printf("|          |\n");
	// printf("|          |\n");
}

void 제목없음() {
}

void 수열() {
	i = 1;
	while (i <= x)
		printf("%d\n", i++);

}

int main() {
	//: T의 값을 달리하여 테스트 케이스의 유형에 대응함
	// -1: 사실상 무한대, 종료 신호까지 입력받음 /  0: 스킵
	//  1: 한 줄의 입력만 주어짐  /  2: 입력받는 횟수가 주어짐

	//: (r,c,h) (n,m,k) (x,y,z) 등이 주어지는 경우 앞에서 먼저 받음.
	// scanf("%d, %d", r, c);
	// scanf("%d, %d, %d", r, c, h);
	// scanf("%d", &n);
	// scanf("%d %d", &n, &m);
	// scanf("%d %d %d", &n, &m, &k);
	// getchar();

	//: 비교할 문자열이 주어지면, (str1, str2)로 썼다가 str로 되돌리기.
	// scanf("%s", str);
	// scanf("%s", str1);
	// getchar();

	T = 0;
	if (T == 2)	{
		scanf("%zd", &T);
		getchar();
	}
	for (size_t t = 1; t <= T; t++) {
		//: scanf가 버퍼에 남겨놓은 공백이 있다면 제거
		if (t > 1) getchar();

		//: 테스트 케이스를 공백으로 구분하는 경우
		if (scanf("%d", &n) == EOF)// || (x == 0) && (y == 0))
			break;

		//: 테스트 케이스를 파싱하여 배열에 기록하는 경우
		// scanf("%d", &seri[t - 1]);

		//: 테스트 케이스를 라인으로 구분하는 경우
		// if (scanf("%[^\n]s", str) == EOF || strcmp(str, "종료신호") == 0)
		// 	break;

		//: 테스트 케이스마다 실행할 내용
		// 단순출력();
		// printf("%d. %s\n", t, str);
		
	}
	//: 추가적으로 입력을 받거나, 위의 방식으로 입력을 받지 않는 경우 (T = 0)
	// scanf("%d", &x);

	//: 입력이 종료되면 실행할 내용
	// 한별이();
	printf("#  # #### #### #  #\n#### #  # #  # # #\n#### #  # #  # # #\n#  # #### #### #  #");

	//: 테스트 케이스가 행렬로 주어지는 경우
	if (r > 0 && c > 0) {
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