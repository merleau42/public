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

int includes(char **strs, char *str);
size_t word_count(char const *s, char c);
char *substr(char const *s, unsigned int start, size_t len);
char **split(char const *s, char c);
char *strjoin(char const *s1, char const *s2);
char *strtrim(char const *s1, char const *set);
void striteri(char *s, void (*f)(unsigned int, char *));
char *strmapi(char const *s, char (*f)(unsigned int, char));
size_t strlcpy(char *dst, const char *src, size_t size);
size_t strlcat(char *dst, const char *src, size_t size);

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
		printf("%d\n", st -> data[st -> top] );
		(st -> top)--;
	}
	else 
		printf("-1\n");
}

void size(Stack *st) {
	printf("%d\n", (st -> top)  + 1);
}

void empty(Stack *st) {
	if (st -> top == -1)
		printf("1\n");
	else
		printf("0\n");

}

void top(Stack *st) {
	if (st -> top == -1)
		printf("-1\n");
	else
		printf("%d\n", st -> data[st -> top]);
}

Stack *new_stack(int size) {
	static Stack instance;

	instance.data = (int *) malloc(sizeof(int) * size);
	instance.top = -1;
	
	return &instance;
}

void main2()
{
	Stack *st;
	st = new_stack(100000);

	push(st, 1);
	push(st, 2);
	top(st);
	size(st);
	empty(st);
	pop(st);
	pop(st);
	pop(st);
	size(st);
	empty(st);
	pop(st);
	push(st, 3);
	empty(st);
	top(st);
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

	t = 1;
	T = -2;
	if (T == -2) {
		scanf("%zd", &T);
		getchar();
	}

	//: 입력을 시작하기 전에 선언할 변수들
	Stack *st;
	st = new_stack(T);
	while (t <= T) {
		//: scanf가 버퍼에 남겨놓은 공백이 있다면 제거
		if (t > 1) getchar();

		//: 테스트 케이스를 공백으로 구분하는 경우
		// if (scanf("%d", &x) == EOF) break;
		// if (scanf("%s", str) == EOF || !strcmp(str, "END")) break;
		// if (scanf("%d", &ser[t - 1]) == EOF) break; // 배열에 차곡차곡

		//: 테스트 케이스를 라인으로 구분하는 경우
		if (scanf("%[^\n]s", str) == EOF || !strcmp(str, "0")) break;

		//: 테스트 케이스를 서식대로 파싱하는 경우
		// if()

		//: 테스트 케이스마다 실행할 내용
		char **input;

		input = split(str, ' ');
		if (strcmp(input[0], "push"))
			push(st, atoi(input[1]));
		if (strcmp(input[0], "pop"))
			pop(st);
		if (strcmp(input[0], "size"))
			size(st);
		if (strcmp(input[0], "empty"))
			empty(st);
		if (strcmp(input[0], "top"))
			top(st);
		//: 다음 테스트 케이스
		t++;
	}
	//: 추가로 입력을 받거나, 정형화되지 않은 방식으로 입력받는 경우
	// scanf("%d", &x);

	//: 입력을 마치면 실행할 내용
	// 

	//: 테스트 케이스가 행렬로 주어지는 경우
	// for (int row = 1; row <= r; i++) {
	// 	for (int col = 1; i <= c; j++) {
	// 		;
	// 	}
	// }
}

// 문자열 배열에서 str이 존재하면 처음 발견한 인덱스를 리턴
// srtstr은 문자열에 str이 존재하는지, include는 문자열 모임에 존재하는지 확인
int includes(char **strs, char *str)
{
	int index;

	index = 0;
	while(strs[index] != NULL)
	{
		if (strcmp(strs[index], str) == 0)
			return index;
		index++;
	}
	return -1; // str이 strs에 포함되지 않는 경우
}

// 문자열 dest에 src를 size-1 바이트 덮어쓰고 쟁여둔 한 자리 널을 넣는 함수
size_t strlcpy(char *dst, const char *src, size_t size)
{
	size_t i;

	if (size == 0)
		return (strlen(src));
	i = 0;
	while (src[i] != '\0' && i + 1 < size)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (strlen(src));
}

// 문자열 dest에 src를 size-dst-1 바이트 이어쓰고 쟁여둔 한 자리 널을넣는 함수
size_t strlcat(char *dst, const char *src, size_t size)
{
	size_t begin_of_null;
	size_t i;

	if (size == 0)
		return (strlen(src));
	i = 0;
	while (dst[i] != '\0' && i < size)
		i++;
	begin_of_null = i;
	if (size <= begin_of_null)
		return (strlen(src) + size);
	i = 0;
	while (src[i] != '\0' && i < size - 1 - begin_of_null)
	{
		dst[begin_of_null + i] = src[i];
		i++;
	}
	dst[begin_of_null + i] = '\0';
	return (strlen(src) + begin_of_null);
}

char *substr(char const *s, unsigned int start, size_t len)
{
	size_t remain;
	size_t s_len;
	char *sub;

	if (!s)
		return (NULL);
	s_len = strlen(s);
	if (s_len > start)
		remain = s_len - start;
	else
	{
		start = 0;
		remain = 0;
	}
	if (len > remain)
		len = remain;
	sub = (char *)malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	strlcpy(sub, s + start, len + 1);
	return (sub);
}

char *strjoin(char const *s1, char const *s2)
{
	size_t len_s1;
	size_t len_s2;
	char *concat;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = strlen(s1);
	len_s2 = strlen(s2);
	concat = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!concat)
		return (NULL);
	strlcpy(concat, s1, len_s1 + 1);
	strlcat(concat, s2, len_s1 + len_s2 + 1);
	return (concat);
}

char *strtrim(char const *s1, char const *set)
{
	size_t start;
	size_t end;
	char *trimmed;

	if (!s1 || !set)
		return (NULL);
	if (s1[0] == '\0' || set[0] == '\0')
		return (strdup(s1));
	start = 0;
	while (strchr(set, s1[start]))
		start++;
	end = strlen(s1);
	if (start > end)
		start = end;
	else
		while (strrchr(set, s1[end - 1]))
			end--;
	trimmed = malloc(sizeof(char) * (end - start + 1));
	if (!trimmed)
		return (NULL);
	strlcpy(trimmed, s1 + start, (end - start + 1));
	return (trimmed);
}

size_t word_count(char const *s, char c)
{
	size_t words;

	words = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			words++;
		while (*s && *s != c)
			s++;
	}
	return (words);
}

char **free_all(char **frame, size_t allocated)
{
	size_t i;

	i = 0;
	while (i < allocated)
		free(frame[i++]);
	free(frame);
	return (NULL);
}

char **split(char const *s, char c)
{
	char **frame;
	size_t words;
	char const *word_start;
	size_t i;

	if (!s)
		return (NULL);
	words = word_count(s, c);
	frame = (char **)malloc(sizeof(char *) * (words + 1));
	i = 0;
	while (frame && i < words)
	{
		while (*s == c)
			s++;
		word_start = s;
		while (*s && *s != c)
			s++;
		frame[i] = substr(word_start, 0, s - word_start);
		if (!frame[i])
			return (free_all(frame, i));
		i++;
	}
	if (frame)
		frame[i] = (char *)0;
	return (frame);
}

char *strmapi(char const *s, char (*f)(unsigned int, char))
{
	char *map;
	char *rewind;

	if (!s || !f)
		return (NULL);
	map = strdup(s);
	rewind = map;
	if (!map)
		return (NULL);
	while (*map)
	{
		*map = (*f)(map - rewind, *map);
		map++;
	}
	return (rewind);
}

void striteri(char *s, void (*f)(unsigned int, char *))
{
	char *rewind;

	if (!s || !f)
		return;
	rewind = s;
	while (*s)
	{
		(*f)(s - rewind, s);
		s++;
	}
}