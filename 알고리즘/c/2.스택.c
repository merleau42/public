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

typedef struct {
	int *data;
	int top;
} Stack;

void push(Stack *st, int x) {
	(st -> top)++;
	st -> data[st -> top] = x;
}

void pop(Stack *st) {
	if (st -> top >= 0) {
		printf("%d", st -> data[st -> top] );
		(st -> top)--;
	}
	else {
		printf("-1");
	}
}

void size(Stack *st) {
	printf("%d", (st -> top)  + 1);
}

void empty(Stack *st) {
	if (st -> top == -1)
		printf("1");
	else
		printf("0");

}

void top(Stack *st) {
	if (st -> top == -1)
		printf("-1");
	else
		printf("%d", st -> data[st -> top]);
}

Stack *new_stack(int size) {
	Stack instance;

	instance.data = (int *) malloc(sizeof(int) * size);
	instance.top = -1;
	
	return &instance;
}

int main()
{
	Stack *st;
	st = new_stack(100000);

	push(st, 1);
	push(st, 2);
	top(st);
	size(st);
}


int main2() {
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