#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>

// 대문자를 소문자로 바꿔주는 함수. 대문자가 아니라면 원본을 리턴
int	ft_tolower(int c)
{
	if ('A' <= c && c <= 'Z')
		return (c + 32);
	return (c);
}

// 소문자를 대문자로 바꿔주는 함수. 소문자가 아니라면 원본을 리턴
int	ft_toupper(int c)
{
	if ('a' <= c && c <= 'z')
		return (c - 32);
	return (c);
}

// 알파벳이면 참을, 아니면 0을 리턴
int	ft_isalpha(int c)
{
	if (('A' <= c && c <= 'Z') \
		|| ('a' <= c && c <= 'z'))
		return (1);
	return (0);
}

// 숫자이면 참을, 아니면 0을 리턴
int	ft_isdigit(int c)
{
	return ('0' <= c && c <= '9');
}

// 영숫자이면 참을, 아니면 0을 리턴
int	ft_isalnum(int c)
{
	return (ft_isdigit(c) || ft_isalpha(c));
}

// 출력 가능한 문자이면 (32 ~ 126) 참을, 아니면 0을 리턴
int	ft_isprint(int c)
{
	return (32 <= c && c <= 126);
}

// 아스키 문자이면 (0 ~ 127) 참을, 아니면 0을 리턴
int	ft_isascii(int c)
{
	return (0 <= c && c <= 127);
}

// 메의리의 n바이트를 c로 덮어쓰고 리턴
// 메모리를 1바이트씩 순회하고, 1바이트씩 덮어씁니다.
// 인자 c는 unsigned char 범위로 형변환되어서 말단의 1바이트만 활용.
void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*bytes;
	size_t			i;

	bytes = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		bytes[i] = (unsigned char) c;
		i++;
	}
	return (s);
}

// 메모리의 n바이트를 ‘\0’으로 덮어쓰는 함수
void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

// 문자열의 길이를 (=바이트 수) 리턴
size_t	ft_strlen(const char *s)
{
	const char	*rewind;

	rewind = s;
	while (*s != '\0')
		s++;
	return (s - rewind);
}

// 문자열에서 문자 c가 처음으로 발견된 주소를 리턴. 존재하지 않으면 NULL을 리턴.
// 널문자도 탐색의 대상이 될 수 있으며, 널-터미네이터의 주소를 리턴합니다.
char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return ((char *) s + i);
		i++;
	}
	if (c == '\0')
		return ((char *) s + i);
	else
		return (NULL);
}

// 문자열에서 문자 c가 마지막으로 발견된 주소를 리턴. 존재하지 않으면 NULL리턴
// 널문자도 탐색의 대상이 될 수 있으며, 널-터미네이터의 주소를 리턴합니다.
char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*last;

	last = NULL;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			last = (char *) s + i;
		i++;
	}
	if (c == '\0')
		return ((char *) s + i);
	else
		return (last);
}

// 메모리영역에서 대상 c가 처음으로 발견된 주소를 리턴. 존재하지 않으면 NULL리턴
// 비교는 unsigned char을 기준으로 이루어짐
void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*bytes;

	bytes = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		if (bytes[i] == (unsigned char) c)
			return ((void *)(bytes + i));
		i++;
	}
	if (c == '\0')
		return ((void *)(bytes + i));
	else
		return (NULL);
}

// 문자열을 복제하고 새로운 문자열로 리턴
char	*ft_strdup(const char *s)
{
	size_t	i;
	size_t	len;
	char	*dest;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	dest = (char *) malloc(sizeof (char) * (len + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

// 메모리 영역 dest에 src를 n바이트 복사하는 함수. dest를 리턴.
// 메모리 영역이 겹치지 않아야 합니다.
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*bytes_d;
	unsigned char	*bytes_s;

	if (!dest || !src)
		return (NULL);
	//if(!dest && !src && n > 0)
	//	return (NULL);
	bytes_d = (unsigned char *) dest;
	bytes_s = (unsigned char *) src;
	i = 0;
	while (i < n)
	{
		bytes_d[i] = bytes_s[i];
		i++;
	}
	return (dest);
}

// 메모리 영역 dest에 src를 n바이트 복사하는 함수. dest를 리턴.
// 메모리 영역이 겹칠 수 있습니다.
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*bytes_d;
	unsigned char	*bytes_s;

	if (!dest || !src)
		return (NULL);
	//if(!dest && !src && n > 0)
	//	return (NULL);
	bytes_d = (unsigned char *) dest;
	bytes_s = (unsigned char *) src;
	i = 0;
	while (i < n)
	{
		if (dest <= src)
			bytes_d[i] = bytes_s[i];
		else
			bytes_d[n - i - 1] = bytes_s[n - i - 1];
		i++;
	}
	return (dest);
}

// 문자열 dest에 src를 size-1 바이트 덮어쓰고 쟁여둔 한 자리 널을넣는 함수
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	if (size == 0)
		return (ft_strlen(src));
	i = 0;
	while (src[i] != '\0' && i + 1 < size)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

// 문자열 dest에 src를 size-dst-1 바이트 이어쓰고 쟁여둔 한 자리 널을넣는 함수
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	begin_of_null;
	size_t	i;

	if (size == 0)
		return (ft_strlen(src));
	i = 0;
	while (dst[i] != '\0' && i < size)
		i++;
	begin_of_null = i;
	if (size <= begin_of_null)
		return (ft_strlen(src) + size);
	i = 0;
	while (src[i] != '\0' && i < size - 1 - begin_of_null)
	{
		dst[begin_of_null + i] = src[i];
		i++;
	}
	dst[begin_of_null + i] = '\0';
	return (ft_strlen(src) + begin_of_null);
}

// 두 문자열의 n자리를 비교하여, 처음으로 불일치하는 쌍의 아스키 차이값을 리턴
// n=0이라면 0을 리턴합니다. 비교는 unsigned char을 기준으로 이루어집니다.
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*bytes_s1;
	unsigned char	*bytes_s2;

	bytes_s1 = (unsigned char *) s1;
	bytes_s2 = (unsigned char *) s2;
	i = 0;
	while (bytes_s1[i] != '\0' || bytes_s2[i] != '\0')
	{
		if (i >= n)
			return (0);
		if (bytes_s1[i] != bytes_s2[i])
			break ;
		i++;
	}
	return (bytes_s1[i] - bytes_s2[i]);
}

// 두 메모리영역 n바이트를 비교하여, 처음으로 불일치하는 쌍의 바이트 차이를 리턴
// n=0이라면 0을 리턴합니다. 비교는 unsigned char을 기준으로 이루어집니다.
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*bytes_s1;
	unsigned char	*bytes_s2;

	bytes_s1 = (unsigned char *) s1;
	bytes_s2 = (unsigned char *) s2;
	i = 0;
	while (1)
	{
		if (i >= n)
			return (0);
		if (bytes_s1[i] != bytes_s2[i])
			break ;
		i++;
	}
	return (bytes_s1[i] - bytes_s2[i]);
}

// 큰 문자열에서 작은 문자열이 처음으로 발견된 주소를 리턴. len범위에 포괄되어야함
// 작은 문자열이 존재하지(포괄되지) 않으면 NULL리턴, 빈문자열이면 큰 문자열 리턴
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	len_ltt;

	if (!big || !little)
		return (NULL);
	//if (!big && !len)
	//	return (NULL);
	if (little[0] == '\0')
		return ((char *) big);
	len_ltt = ft_strlen(little);
	i = 0;
	while (big[i] != '\0' && i < len)
	{
		if (len - i < len_ltt)
			break ;
		if (big[i] == little[0])
			if (ft_strncmp(big + i, little, len_ltt) == 0)
				return ((char *) big + i);
		i++;
	}
	return (NULL);
}

// 크기가 size씩인 연속적인 nmemb칸의 메모리 공간을 할당하고 리턴. 0으로 초기화.
// size=0 혹은 nmemb=0 이라면 free() 될 수 있는 고유한 메모리 주소를 리턴.
// size * nmemb 으로 정수 오버플로우가 발생하면 오류를 리턴합니다.
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*alloc;

	if (size == 0 || nmemb == 0)
		return (malloc(0));
	if (INT_MAX / size < nmemb)
		return (NULL);
	alloc = malloc(nmemb * size);
	if (!alloc)
		return (NULL);
	ft_memset(alloc, 0, nmemb * size);
	return (alloc);
}

// 수를 ‘숫자 문자열’ 로 변환하여 리턴합니다.
// malloc을 사용하여 새로운 메모리 영역을 할당합니다. 실패하면 NULL 리턴.
char	*ft_itoa(int n)
{
	char	conv[11];
	int		start;
	int		i;
	int		sign;

	sign = (n < 0);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	else
	{
		i = 11;
		start = 10;
		while (i--)
		{
			conv[i] = (n * (1 - 2 * sign)) % 10 + '0';
			n = n / 10;
			if (conv[i] != '0')
				start = i;
		}
		conv[start - 1] = '-';
		return (ft_strdup(conv + start - sign));
	}	
}

// 문자열에서 ‘숫자’를 발굴하고, 수로 변환해서 리턴.
int	ft_atoi(const char *nptr)
{
	int	res;
	int	sign;
	int	i;

	res = 0;
	sign = 1;
	i = 0;
	while ((9 <= nptr[i] && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
		sign = sign * (44 - nptr[i++]);
	if (nptr[i] == '-' || nptr[i] == '+')
		return (0);
	while ('0' <= nptr[i] && nptr[i] <= '9')
		res = 10 * res + nptr[i++] - '0';
	return (res * sign);
}

// 문자열의 인덱스 start부터 최대 len바이트만큼, 부분 문자열 추출하고 리턴
// malloc을 사용하여 새로운 메모리 영역을 할당합니다. 실패하면 NULL 리턴
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	remain;
	size_t	s_len;
	char	*sub;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (s_len > start)
		remain = s_len - start;
	else
	{
		start = 0;
		remain = 0;
	}
	if (len > remain)
		len = remain;
	sub = (char *) malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	ft_strlcpy(sub, s + start, len + 1);
	return (sub);
}

// 두 개의 문자열 s1과 s2를 이어붙여서, 연결 문자열을 생성하고 리턴합니다.
// malloc을 사용하여 연결 문자열의 메모리를 할당합니다. 실패하면 NULL리턴
char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*concat;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	concat = (char *) malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!concat)
		return (NULL);
	ft_strlcpy(concat, s1, len_s1 + 1);
	ft_strlcat(concat, s2, len_s1 + len_s2 + 1);
	return (concat);
}

// 문자열 양쪽 끝에서, 사전에 수록된 문자들을 모두 제거한 새로운 문자열 리턴
// malloc을 사용하여 새로운 문자열의 메모리를 할당합니다. 실패하면 NULL 리턴
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*trimmed;

	if (!s1 || !set)
		return (NULL);
	if (s1[0] == '\0' || set[0] == '\0')
		return (ft_strdup(s1));
	start = 0;
	while (ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1);
	if (start > end)
		start = end;
	else
		while (ft_strrchr(set, s1[end - 1]))
			end--;
	trimmed = malloc(sizeof(char) * (end - start + 1));
	if (!trimmed)
		return (NULL);
	ft_strlcpy(trimmed, s1 + start, (end - start + 1));
	return (trimmed);
}

static	size_t	ft_word_count(char const *s, char c)
{
	size_t	words;

	words = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			words++;
		while (*s != '\0' && *s != c)
			s++;
	}
	return (words);
}

// 구분자를 기준으로 문자열을 분할하여 얻어지는, 부분 문자열들의 배열을
// 리턴합니다 malloc을 사용하여 하위 문자열과 문자열 배열의 메모리를 할당하고
// 실패하면 NULL을 리턴 free를 사용할 수 있습니다
char	**ft_split(char const *s, char c)
{
	char		**frame;
	size_t		words;
	size_t		len;
	size_t		i;

	words = ft_word_count(s, c);
	frame = (char **) malloc(sizeof(char *) * (words + 1));
	if (!frame)
		return (NULL);
	i = 0;
	while (i < words)
	{
		while (*s == c)
			s++;
		len = 0;
		while (*s != '\0' && *s != c)
		{
			s++;
			len++;
		}
		frame[i++] = ft_substr(s - len, 0, len);
	}
	frame[i] = (char *) 0;
	return (frame);
}

// 문자열을 순회하여, 각각의 문자와 인덱스를 함수 f에 전달하고,
// 그 반환값의 배열을 리턴
// malloc을 사용하여 새로운 문자열의 메모리를 할당합니다. 실패하면 NULL 리턴
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*map;
	char	*rewind;

	if (!s || !f)
		return (NULL);
	map = ft_strdup(s);
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

// 문자열을 순회하여, 문자 주소와 인덱스를 함수 f에 전달하고,
// 반환값으로 기존 문자를 변경할 수 있음
void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	char	*rewind;

	if (!s || !f)
		return ;
	rewind = s;
	while (*s)
	{
		(*f)(s - rewind, s);
		s++;
	}
}

// 파일 디스크립터 fd에 상응하는 파일에 문자를 출력합니다
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

// 파일 디스크립터 fd에 상응하는 파일에 문자열을 출력합니다
void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, ft_strlen(s));
}

// 파일 디스크립터 fd에 상응하는 파일에 문자열을 개행 문자와 함께 출력합니다.
void	ft_putendl_fd(char *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, ft_strlen(s));
	write(fd, "\n", 1);
}

// 파일 디스크립터 fd에 상응하는 파일에 정수를 숫자 문자열로 출력합니다
void	ft_putnbr_fd(int n, int fd)
{
	char	conv[10];
	char	start;
	int		i;

	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			write(fd, "-", 1);
			n = -n;
		}
		i = 10;
		start = 9;
		while (i--)
		{
			conv[i] = n % 10 + '0';
			n = n / 10;
			if (conv[i] != '0')
				start = i;
		}
		write(fd, conv + start, 10 - start);
	}	
}

char	fn(unsigned int i, char c)
{
	(void) i;
	if ('A' <= c && c <= 'Z')
		return (c + 32);
	if ('a' <= c && c <= 'z')
		return (c - 32);
	return (c);
}

void	ffn(unsigned int i, char *c)
{
	(void) i;
	if (ft_isdigit(*c))
		printf("수");
	if (ft_isalpha(*c))
		printf("알");
}

#include <string.h>
#include <stdlib.h>
int main(void)
{
	const char *s = "11221abcd321EFGHI23mnZ33211";
	printf("original:\n%s\n", s);
	printf("substr:\n%s\n", ft_substr(s, 7, 7));
	printf("iteri:\n");
	ft_striteri(ft_strdup(s), ffn);
	printf("\nmap:\n%s\n", ft_strmapi(s, fn));
	printf("trim:\n%s\n", ft_strtrim(s, "123"));
	printf("strnstr:\n%s\n", ft_strnstr(s, "HI", 33));

	//int tab[]=
	//{-2147483648, -2147483647, -4525, -10, -9, -8, -2, -1, 0,
	//  2147483647,  2147483646,  4525,  10,  9,  8,  2,  1, 0};
	//for (int i = 0; i < 18; i++)
	//	printf("/%d\\\n\\%s/\n", tab[i], ft_itoa(tab[i]));
	
	char w;
	char** tk[50]={0};
	w = '1';
	printf("\nstrim: %s\n\n", ft_strtrim("111aba321411wqwe11111", &w));

	printf("[5: 2 6 8 6 3]\n");
	printf("[2: 2 6]\n");
	printf("[1: 6]\n");
	printf("[0: 0]\n");
	tk[0] = ft_split("__ad___eqwewe__dsasadsd___gaksad___das__", '_');
	tk[1] = ft_split("__ad___eqwewe__dsasadsd___gaksad___das_", '_');
	tk[2] = ft_split("__ad___eqwewe__dsasadsd___gaksad___das", '_');
	tk[3] = ft_split("_ad___eqwewe__dsasadsd___gaksad___das__", '_');
	tk[4] = ft_split("ad___eqwewe__dsasadsd___gaksad___das__", '_');
	tk[5] = ft_split("_ad___eqwewe__dsasadsd___gaksad___das_", '_');
	tk[6] = ft_split("ad___eqwewe__dsasadsd___gaksad___das", '_');
	tk[7] = ft_split("__ad___eqwewe___", '_');
	tk[8] = ft_split("_ad___eqwewe___", '_');
	tk[9] = ft_split("ad___eqwewe___", '_');
	tk[10] = ft_split("__ad___eqwewe_", '_');
	tk[11] = ft_split("__ad___eqwewe", '_');
	tk[12] = ft_split("_ad___eqwewe_", '_');
	tk[13] = ft_split("ad___eqwewe", '_');
	tk[14] = ft_split("___eqwewe___", '_');
	tk[15] = ft_split("_eqwewe___", '_');
	tk[16] = ft_split("eqwewe___", '_');
	tk[17] = ft_split("___eqwewe_", '_');
	tk[18] = ft_split("___eqwewe", '_');
	tk[19] = ft_split("_eqwewe_", '_');
	tk[20] = ft_split("eqwewe", '_');
	tk[21] = ft_split("___", '_');
	tk[22] = ft_split("__", '_');
	tk[23] = ft_split("_", '_');
	tk[24] = ft_split("", '_');
	for (int i=0; i<=24; i++)
	{
		for (int j=0; tk[i][j] != NULL; j++)
			printf("%s  ", tk[i][j]);
		printf("\n");
	}

	printf("-----정교화 시작-----\n");
	int a, b;
	printf("%d\n", (ft_memset(&a, 5 ,2), a) );
	printf("%d\n", (   memset(&b, 5 ,2), a) );

	printf("%d\n", (ft_bzero(&a, 4), a) );
	printf("%d\n", (   bzero(&b, 4), a) );

	printf("1:%s\n", ft_strtrim("    asdasdasdsa    ", "\t \n"));
	printf("2:%s\n", ft_strtrim(" ", "\t \n"));
	printf("3:%s\n", ft_strtrim("  ", "\t \n"));
	printf("4:%s", ft_strtrim("          ", "\t \n"));

	printf("-----strlcat-----\n");
	char	*dest;
	dest = (char *)malloc(sizeof(*dest) * 15);
	ft_memset(dest, 'r', 15);
	// rrrrrrrrrrrrrrr
	printf("%zu", ft_strlcat(dest, "lorem ipsum dolor sit amet", 5));
	write(1, "\n", 1);
	write(1, dest, 15);

}
