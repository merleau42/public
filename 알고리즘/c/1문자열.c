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
char exist[256];
int count;
int sum;
void *rewind_;
int seri[1000000];
char *entered[1000000];
char enter;
int i, j, k;
int r, c, h;
int x, y, z;
int n, m;
int scanned;

void 파싱()
{
	//: 기호 +를 기준으로 양옆의 숫자를 파싱하고, 정수로 변환해서 합산
	// parsed = split(str, '+');
	// printf("%d\n", atoi(parsed[0]) + atoi(parsed[1]));

	//: 기호 -를 기준으로 뒤에 오는 숫자를 파싱하고, 정수로 변환해서 합산
	// parsed = split(str, '-');
	// if (atoi(parsed[1]) <= 90)
	// 	count++;
}

void 누적()
{
	sum = 0;
	i = 0;
	while (i < n)
	{
		sum += str[i] - '0';
		i++;
	}
	printf("%d", sum);
}

void 수열()
{
	parsed = split(str, ',');

	i = -1;
	while(parsed[++i] != NULL)
	{
		seri[i] = atoi( parsed[i] );
		// sum += atoi( parsed[i] ); 수열의 합
	}

	while(k--)
	{
		i = -1;
		while(++i < n)
			seri[i] = seri[i+1] - seri[i];
		n--;
	}

	i = -1;
	while(++i < n-1)
		printf("%d,", seri[i]);
	printf("%d", seri[i]);
}

void 단어갯수()
{
	count = word_count(str, ',');
	printf("%d", count);
}

void 길이()
{
	len = strlen(str);
	if (6 <= len && len <= 9)
		printf("yes\n");
	else
		printf("no\n");
}

void 인덱싱()
{
	//: 반복되는 문자열 전체에서 n번째 접근
	// printf("%c", "WelcomeToSMUPC"[(n - 1) % 14]);
	// printf("%c", str[(n - 1) % strlen(str)]);

	//: 문자열 끝에서 다섯 글자만 출력
	// write(1, str + len - 5, 5);

	//: 마침표 없는 문장에 마침표 찍기
	// if (str[strlen(str) - 1] == '.')
	// 	printf("%s\n", str);
	// else
	// 	printf("%s.\n", str);
}

void 가공()
{
	;
}

void 분류하기()
{
	if (!strcmp(str, "NLCS"))
		printf("North London Collegiate School");
	if (!strcmp(str, "BHA"))
		printf("Branksome Hall Asia");
	if (!strcmp(str, "KIS"))
		printf("Korea International School");
	if (!strcmp(str, "SJA"))
		printf("St. Johnsbury Academy");
}

void 포함1()
{
	char *said[8] =
		{"Never gonna give you up",
		"Never gonna let you down",
		"Never gonna run around and desert you",
		"Never gonna make you cry",
		"Never gonna say goodbye",
		"Never gonna tell a lie and hurt you",
		"Never gonna stop",
		NULL};

	char *msg = "No";
	if (includes(said, str) == -1)
		msg = "Yes";
}

void 포함2()
{
	// DKKSSH
	// HDKSHDDKS
	// SDKSHSSDKSHS
	char *new_str;

	count = 0;
	new_str = str;
	while (strlen(new_str) >= 4)
	{
		new_str = strstr(new_str, "DKSH");
		if (new_str)
		{
			new_str += 4;
			count++;
		}
		else
			break;
	}
	printf("%d", count);
}

void 문자열비교()
{
	//: 더 짧은 문자열 혹은 아스키코드상 앞서는 문자열을 출력
	// if (strcmp(str1, str2) > 0)
	// 	printf("str2");
	// else
	// 	printf("str1");

	//: 문자열에 따라 다르게 출력
	// if (strcmp(str, "P=NP") == 0)
	// {
	//	printf("skipped\n");
	//	return ;
	// }

	//: 일치하는 문자열의 갯수
	// if (strcmp(str1, str2) == 0)
	// 	count++;
}

void 문자판독()
{
	i = -1;
	count = 0;
	while(str[++i]) //: 문자열 순회중
	{
		//: 대문자를 소문자로 전환, 소문자를 대문자로 전환
		// if('A' <= str[i] && str[i] <= 'Z')
		// 	printf("%c", str[i] + 32);
		// else if('a' <= str[i] && str[i] <= 'z')
		// 	printf("%c", str[i] - 32);
		// else
		// 	printf("%c", str[i]);

		//:	알파벳 모음 갯수
		// if (strchr("aeiouAEIOU", str[i]) != NULL)
		// 	count++;

		//: 일부 알파벳만 대소문자 전환 (e,E) <---> (i,I)
		// if ('e' == str[i] || 'E' == str[i])
		// 	printf("%c", str[i] - 5 + 9);
		// else if ('i' == str[i] || 'I' == str[i])
		// 	printf("%c", str[i] - 9 + 5);
		// else
		// 	printf("%c", str[i]);

		//: 문자마다 가중치를 달리하여서 합산
		// if (':' == str[i])
		// 	count += 2;
		// else if ('_' == str[i])
		// 	count += 6;
		// else
		// 	count += 1;
	}
	// printf("\n");
	printf("%d\n", count);
}

void 순서뒤집기() // 스택으로 다시 풀어보기
{
	parsed = split(str, ' ');
	rewind_ = parsed;
	while (*parsed)
		parsed++;
	printf("Case #%zd: ", t);
	while (parsed != rewind_)
		printf("%s ", *--parsed);
	printf("\n");
}

void 문자열뒤집기()
{
	len = strlen(str);
	while(--len >= 0)
		printf("%c", str[len]);
	printf("\n");
}

void 계수()
{
	//: 존재 배열에 문자의 갯수를 카운팅
	i = -1;
	while(str[++i])
		exist[(int) str[i]]++;

	//: 알파벳 소문자의 수집 상태를 표시
	// i = 'a';
	// while(i <= 'z')
	// 	printf("%d ", exist[i++]);
	
	//: 문자들의 수집 여부를 확인
	if (exist['M'] * exist['O'] * exist['B'] * exist['I'] * exist['S'])
		printf("YES");
	else
		printf("NO");
}

void 축약()
{
	enter = '\0';
	i = 0;
	j = 0;
	while (str[i])
	{
		if(enter != str[i])
		{
			enter = str[i];
			entered[j++] = &str[i];
		}
		entered[j] = "\n";
		i++;
	}
	k = 0;
	while (k <= j)
		printf("%c", *entered[k++]);
}

void 형식문자열()
{
	scanf("%d + %d = %d", &x, &y, &z); getchar();
	if (x + y == z)
		printf("YES");
	else
		printf("NO");
}

void 슬라이딩윈도우()
{
	// https://www.acmicpc.net/problem/29766
}

// sorting, greedy, data_structures

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
	// scanf("%s", str1);
	// getchar();

	T = 2;
	if (T == 2)	{
		scanf("%zd", &T);
		getchar();
	}
	for (size_t t = 1; t <= T; t++) {
		//: scanf가 버퍼에 남겨놓은 공백 제거
		if (t > 1) getchar();

		//: 테스트 케이스를 공백으로 구분하는 경우
		// if (scanf("%d", &x) == EOF) // || x = '종료신호')
		// 	break;

		//: 테스트 케이스를 파싱하여 배열에 기록하는 경우
		scanf("%d", &seri[t - 1]);

		//: 테스트 케이스를 라인으로 구분하는 경우
		// if (scanf("%[^\n]s", str) == EOF || strcmp(str, "종료신호") == 0)
		// 	break;

		//: 테스트 케이스마다 실행할 내용
		// printf("%d. %s\n", t, str);
		
	}
	//: 추가적으로 입력을 받거나, 위의 방식으로 입력을 받지 않는 경우 (T = 0)
	scanf("%d", &x);

	//: 입력이 종료되면 실행할 내용
	대소비교();

	//: 행렬이 주어지는 경우
	if (r > 0 && c > 0) {
		for (int i = 1; i <= r; i++) {
			if (i > 1) getchar();
			scanf("%[^\n]s", str);
			대소비교();
			// for (int j = 1; i <= c; j++){
			// 	;
			// }
		}
	}
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