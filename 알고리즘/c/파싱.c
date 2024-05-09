#include <stdio.h>
// 출력 ㅡ 영역(값)▶콘솔 ㅡ printf
// 입력 ㅡ 영역(값)▶변수 ㅡ scanf

#include <unistd.h>
// 출력 ㅡ 문자열▶FD ㅡ write

#include <stdlib.h>
// 변환 ㅡ 배열▶정수 ㅡ atoi
// 변환 ㅡ 정수▶배열 ㅡ itoa
// 할당 ㅡ 배열▶영역 ㅡ malloc, calloc

#include <string.h>
// 대입 ㅡ 값▶영역 ㅡ memset, bzero
// 비교 ㅡ 값▶값 ㅡ strlen, strchr, strrchr, memchr
// 비교 ㅡ 영역▶영역 ㅡ strncmp, memcmp, strnstr
// 복제 ㅡ 영역▶영역 ㅡ strdup, memmove, strlcpy, strlcat

#include <limits.h>

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
int T=1, t=0; // 테스트 케이스
char **parsed;
char  str[1000000]; int len;
char str1[1000000]; int len1;
char str2[1000000]; int len2;
int count;
int sum;
void *rewind_;
int seri[1000000];
int n;
int i;

void p26068()
{
	scanf("%d", &T);
	count = 0;
	while (T--)
	{
		scanf("%s", str1);
		parsed = split(str1, '-');
		if (atoi(parsed[1]) <= 90)
			count++;
	}
	printf("%d", count);
}

void p5026() // p10953
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%s", str1);
		if (!strcmp(str1, "P=NP"))
		{
			printf("skipped\n");
			continue;
		}
		parsed = split(str1, '+');
		printf("%d\n", atoi(parsed[0]) + atoi(parsed[1]));
	}
}

void p12605v1() /// 스택으로 다시 풀어보기
{
	scanf("%d", &T);
	while (++t <= T)
	{
		scanf(" %[^\n]s", str1);
		parsed = split(str1, ' ');
		rewind_ = parsed;
		while (*parsed)
			parsed++;
		printf("Case #%d: ", t);
		while (parsed != rewind_)
			printf("%s ", *--parsed);
		// scanf("%d", &dummy);
		printf("\n");
	}
}

void p1551() // https://www.acmicpc.net/problem/1551
{
	int n, k;
	
	scanf("%d %d", &n, &k);
	scanf("%s", str1);

	parsed = split(str1, ',');

	i = -1;
	while(parsed[++i] != NULL)
		seri[i] = atoi( parsed[i] );
	
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

void p10822()
{
	scanf("%s", str1);
	parsed = split(str1, ',');
	while (*parsed != NULL)
		sum += atoi(*parsed++);
	printf("%d", sum);
}

void p10821()
{
	scanf("%s", str1);
	count = word_count(str1, ',');
	printf("%d", count);
}

// void p3447() //: 버그왕
// {
// 	char* parsed[101];
// 	rewind_ = parsed;
// 	while(scanf("%s", str1) != EOF) 
// 	{
// 		*(parsed++) = str1;
// 	}
// 	parsed = rewind_;
// 	while(*parsed != NULL)
// 		printf("%s", *parsed++);
// }

void p25372() // 단어 길이 관련: 2743(길이출력)
{
	scanf("%d", &i);
	while (scanf("%s", str1) != EOF) { // i를 더미로 삼을 경우, ctrl + D 로 EOF 전달 가능
		len = strlen(str1);
		if (6 <= len && len <= 9)
			printf("yes\n");
		else
			printf("no\n");
	}
}

void p29699() // 인덱싱:27866()
{
	scanf("%d", &n);
	printf("%c", "WelcomeToSMUPC"[(n - 1) % 14]);
}

void p27889() // 문자열 분류: 28691, 
{
	scanf("%s", str1);
	if (!strcmp(str1, "M"))
		printf("MatKor");
	if (!strcmp(str1, "W"))
		printf("WiCys");
	if (!strcmp(str1, "C"))
		printf("CyKor");
	if (!strcmp(str1, "A"))
		printf("AlKor");
	if (!strcmp(str1, "$"))
		printf("$clear");
}

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

void p29731() // 문자열 비교:
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
	scanf("%d", &T);
	while (++t <= T)
	{
		scanf(" %[^\n]s", str);
		if (includes(said, str) == -1)
			msg = "Yes";
	}
	printf("%s", msg);

// 2
// Never gonna give you up
// Never gonna say goodbye
}

void pNONE() // 문자열 입출력:
{
	scanf("%d", &T);
	while (++t <= T)
	{
		scanf(" %[^\n]s", str);
		printf("%s\n", str);
	}
}

void p2744() // 문자 판독: 18409, 15000
{
	int i;

	scanf("%d", &i);
	scanf("%s", str1);

	i = 0;
	count = 0;
	while(str1[i])
	{
		// if('A' <= str1[i] && str1[i] <= 'Z')
			// printf("%c", str1[i] + 32);
		// else if('a' <= str1[i] && str1[i] <= 'z')
			// printf("%c", str1[i] - 32);
		if (strchr("aeiou", str1[i]) != NULL)
			count++;
		i++;
	}
	printf("%d", count);
}

void p4999()
{
	int i;

	scanf("%s\n%s", str1, str2);

	if (strcmp(str1, str2) > 0)
		printf("no");
	else
		printf("go");
	
}

void p8545() // 거꾸로 출력
{
	scanf("%s", str1);

	len = strlen(str1);
	while(--len >= 0)
		printf("%c", str1[len]);
}

void p9086() // 첫글자 끝글자
{
	scanf("%d", &T);
	while (++t <= T)
	{
		scanf(" %[^\n]s", str1);
		printf("%c", *str1);
		i = 0;
		while(str1[i])
			i++;
		printf("%c\n", str1[i - 1]);
	}
}
// 한 문장에 공백 포함시 scanf(" %[^\n]s", str1);
int main()
{
	p29731();
	// sorting, greedy
	// data_structures: linked_list stack queue deque
}

// 문자열 dest에 src를 size-1 바이트 덮어쓰고 쟁여둔 한 자리 널을넣는 함수
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