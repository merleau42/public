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
int found;
int sum;
void *rewind_;
int ser[1000000];
char *entered[1000000];
char enter;
int a, b;
int n, m;
int i, j, k;
int r, c, h;
int x, y, z;
char ch;
char *tmp;

void 중첩반복문()
{
	int i;
	int j;
	int min_j = 0, max_j = c;
	int min_i = 0, max_i = r;

	i = min_i;
	while (i < max_i)
	{
		j = min_j;
		while (j < max_j)
		{
			// printf("%d * %d = %d\n", i, j, i*j); // 구구단

			if (i >= j)
			printf("*");

			j++;
		}
		printf("\n");
		i++;
	}
}

void 사칙연산()
{
	int i;
	i = 0;
	while (i < x)
	{
		printf("SciComLove\n");
		i++;
	}
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

int 중간값()
{
	int max;
	max = -2147483647;

	if (x == y || x == z)
		return printf("%d", x);
	if (y == x || y == z)
		return printf("%d", y);
	if (z == x || z == y)
		return printf("%d", z);
	if ((x > y && y > z) || (z > y && y > x))
		return printf("%d", y);
	if ((y > z && z > x) || (x > z && z > y))
		return printf("%d", z);
	if ((z > x && x > y) || (y > x && x > z))
		return printf("%d", x);
}

void 비교()
{
	if (x == 'N' || x == 'n')
		printf("Naver D2");
	else
		printf("Naver Whale");
}

void 범위()
{
	if (620 <= x && x <= 780) printf("Red");
	if (590 <= x && x < 620) printf("Orange");
	if (570 <= x && x < 590) printf("Yellow");
	if (495 <= x && x < 570) printf("Green");
	if (450 <= x && x < 495) printf("Blue");
	if (425 <= x && x < 450) printf("Indigo");
	if (380 <= x && x < 425) printf("Violet");
}

void 케이스()
{
	//: 문자열에 대응하는 문자열을 출력 (키-밸류 방식)
	// char *a[] = { "Algorithm", "DataAnalysis", "ArtificialIntelligence",
	// 			"CyberSecurity", "Network",	"Startup", "TestStrategy" };
	// char *b[] = { "204", "207", "302", "B101", "303", "501", "105" };
	
	// for (int i = 0; i < 7; i++)
	// 	if (strcmp(str, a[i]) == 0 )
	// 		printf("%s\n", b[i]);

	//: 숫자에 대응하는 문자열을 출력
	char *a[] = { "", "12 1600", "11 894", "11 1327", "10 1311", "9 1004", "9 1178", "9 1357", "8 837", "7 1055", "6 556", "6 773" };
	printf("%s", a[x]);
}

void 수열()
{
	int i, end;

	//: 수열의 순회
	i = 0; end = T;
	while (i < end) {

		//: 값 비교
		if (ser[i] != 0 && ser[i] != 1) {
			// found++;		// 일치하는 값의 갯수
			// count++;		// 일치하는 상태의 수
			printf("F");		// 일치하는 경우 출력
			// break;		// 일치하는 경우 종료
			return;		// 일치하는 경우 종료
		}

		//: 원소 출력
		// printf("%d ", ser[i]);

		i++;
	}
	
	//: 수열의 정보 출력
	// printf("%d", i);			// 수열의 원소 갯수
	// printf("%d", found);		// 일치하는 값의 갯수
	// printf("%d", count);		// 일치하는 상태의 수
	printf("S");
}

// 4 1 1 3 0 9 6 7

void 수열2() {
	i = 1;
	while (i <= x)
		printf("%d\n", i++);

}

void 서식(int t)
{
	//: 변수의 원본과 복사본을 나란히 출력
	printf("%d %d\n", x, x);

	//: char 변수를 %d로 출력
	// printf("%d", ch);

	//: 팬들에게 둘러쌓인 홍준
	// char *fan;
	// fan = ":fan:";
	// printf("%s%s%s\n%s:%s:%s\n%s%s%s",fan,fan,fan,fan,str1,fan,fan,fan,fan);
	// printf(":fan::fan::fan:\n:fan::%s::fan:\n:fan::fan::fan:",str1);

	//: 입력받은 행 번호를 출력
	// printf("Case %d: Sorting... done!\n", t);
	// printf("%d. %s\n", t, str);
}

void 그대로출력()
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

void 반복()
{
	while(x--)
		그대로출력();
}

int main() {
	//: (r,c,h) (n,m,k) (x,y,z) 등이 주어지는 경우 앞에서 먼저 받음.
	// scanf("%d %d", &r, &c);
	// scanf("%d %d %d", &r, &c, &h);
	// scanf("%d, &n);
	// scanf("%d %d", &n, &m);
	// scanf("%d %d %d", &n, &m, &k);
	// scanf("%d", &x);
	// scanf("%d %d", &x, &y);
	// scanf("%d %d %d", &x, &y, &z);
	// getchar();

	//: 비교할 문자열이 주어지면, (str1, str2)로 썼다가 str로 돌려놓기.
	// scanf("%s", str);
	// scanf("%s", str1);
	// getchar();

	//: T의 값을 달리하여 테스트 케이스의 유형에 대응함
	//  1: 한 줄의 입력만 주어짐 (T = 1)
	//	0: 정형화되지 않은 입력 방식 (T = 0)
	// -1: 사실상 무한대, 종료 신호까지 입력받음 (공E)
	// -2: 입력받는 횟수가 주어짐 (공N)

	T = 1;
	if (T == -2) {
		scanf("%zd", &T);
		getchar();
	}
	t = 1;
	while (t <= T) {
		//: scanf가 버퍼에 남겨놓은 공백이 있다면 제거
		if (t > 1) getchar();

		//: 테스트 케이스를 공백으로 구분하는 경우
		if (scanf("%d", &x) == EOF) break;
		// if (scanf("%s", str) == EOF || !strcmp(str, "END")) break;
		// if (scanf("%d", &ser[t - 1]) == EOF) break; // 배열에 차곡차곡

		//: 테스트 케이스를 라인으로 구분하는 경우
		// if (scanf("%[^\n]s", str) == EOF || !strcmp(str, "0")) break;

		//: 테스트 케이스를 서식대로 파싱하는 경우
		// if()

		//: 테스트 케이스마다 실행할 내용
		// 중첩반복문();
		// 사칙연산();
		// 정밀도();
		// 정수론();
		// 중간값();
		// 비교();
		케이스();
		// 수열();
		// 수열2();
		// 비교();
		// 범위();
		// 반복();
		// 그대로출력();
		
		//: 다음 테스트 케이스
		t++;
	}
	//: 추가로 입력을 받거나, 정형화되지 않은 방식으로 입력받는 경우
	// scanf("%d", &x);

	//: 입력을 마치면 실행할 내용
	// 중첩반복문();
	// 사칙연산();
	// 정밀도();
	// 정수론();
	// 중간값();
	// 비교();
	// 케이스();
	// 수열();
	// 수열2();
	// 비교();
	// 범위();
	// 반복();
	// printf("%d", t - 1);		// 줄의 갯수
	// 그대로출력();

	//: 테스트 케이스가 행렬로 주어지는 경우
	// for (int row = 1; row <= r; i++) {
	// 	for (int col = 1; i <= c; j++) {
	// 		;
	// 	}
	// }
}