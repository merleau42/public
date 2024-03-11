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
	size_t			idx;

	bytes = (unsigned char *) s;
	idx = 0;
	while (idx < n)
	{
		bytes[idx] = (unsigned char) c;
		idx++;
	}
	return (bytes);
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
	while (bytes[i] != '\0')
	{
		if (bytes[i] == c)
			return ((void *) bytes + i);
		i++;
	}
	if (c == '\0')
		return ((void *) bytes + i);
	else
		return (NULL);
}

// 문자열을 복제하고 새로운 문자열로 리턴
char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*dest;

	dest = (char *) malloc(sizeof (char) * (ft_strlen(s) + 1));
	i = 0;
	while (dest[i] != '\0')
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

	bytes_d = (unsigned char *) dest;
	bytes_s = (unsigned char *) src;
	i = 0;
	while (bytes_d[i] != '\0' && i < n)
	{
		bytes_d[i] = bytes_s[i];
		i++;
	}
	bytes_d[i] = '\0';
	return (dest);
}

// 메모리 영역 dest에 src를 n바이트 복사하는 함수. dest를 리턴.
// 메모리 영역이 겹칠 수 있습니다.
void	*ft_memmove(void *dest, const void *src, size_t n)
{
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
	while (dst[i] != '\0')
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

	if (!little)
		return (NULL);
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
	if (size == 0 || nmemb == 0)
		return (malloc(0));
	if (INT_MAX / size < nmemb)
		return (NULL);
	return ft_memset(malloc(nmemb * size), 0, nmemb * size);
}

// 수를 ‘숫자 문자열’ 로 변환하여 리턴합니다.
// malloc을 사용하여 새로운 메모리 영역을 할당합니다. 실패하면 NULL 리턴.
char	*ft_itoa(int n)
{
}

// 문자열에서 ‘숫자’를 발굴하고, 수로 변환해서 리턴.
int	ft_atoi(const char *nptr)
{
	int res;
	int sign;
	int i;

	res = 0;
	sign = 1;
	i = 0;
	while ((9 <= nptr[i] && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
		sign = sign * (44 - nptr[i++]); // 음의 부호는 45, 양의 부호는 43
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
	char	*sub;

	remain = ft_strlen(s + start);
	if (len > remain)
		len = remain;
	sub = (char *) malloc(sizeof(char) * (len + 1));
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
	char*	trimmed;

	if (!s1 || !set)
		return NULL;
	if (s1[0] == '\0' || set[0] == '\0')
		return ft_strdup(s1);
	start = 0;
	while (ft_strchr(set,s1[start]))
		start++;
	end = ft_strlen(s1) - 1;
	while (ft_strrchr(set,s1[end]))
		end--;
	trimmed = malloc(sizeof(char) * (end - start + 1 + 1));
	ft_strlcpy(trimmed, s1 + start, (end - start + 1 + 1));
	return trimmed;
}

// 구분자를 기준으로 문자열을 분할하여 얻어지는, 부분 문자열들의 배열을
// 리턴합니다 malloc을 사용하여 하위 문자열과 문자열 배열의 메모리를 할당하고
// 실패하면 NULL을 리턴 free를 사용할 수 있습니다
char	**ft_split(char const *s, char c)
{
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
	while (*map != '\0')
	{
		*map = (*f)(map - rewind, *map);
		map++;
	}
	return rewind;
}

// 문자열을 순회하여, 문자 주소와 인덱스를 함수 f에 전달하고,
// 반환값으로 기존 문자를 변경
void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	char	*rewind;

	if (!s || !f)
		return ;
	rewind = s;
	while (*s != '\0')
	{
		(*f)(s - rewind, s);
		s++;
	}
}

// 파일 디스크립터 fd 에 상응하는 파일에 문자를 출력합니다
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

// 파일 디스크립터 fd 에 상응하는 파일에 문자열을 출력합니다
void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}

// 파일 디스크립터 fd 에 상응하는 파일에 문자열을 개행 문자와 함께 출력합니다.
void	ft_putendl_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
	write(fd, "\n", 1);
}

// 파일 디스크립터 fd 에 상응하는 파일에 정수를 숫자 문자열로 출력합니다
void	ft_putnbr_fd(int n, int fd)
{
	char conv[10];
	char start;
	int i;

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

char fn(unsigned int i, char c)
{
	if ('A' <= c && c <= 'Z')
		return c + 32;
	if ('a' <= c && c <= 'z')
		return c - 32;
	return c;
}

int main(void)
{
	char *s = "abcdEFGHI23mnZ";
	printf("%s\n", s);
	printf("%s", ft_strmapi(s, fn));
}