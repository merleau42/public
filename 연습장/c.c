#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

size_t	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(const char *str, int c)
{
	char		*s;
	size_t		i;

	s = (char *)str;
	i = 0;
	while (i < ft_strlen(s))
	{
		if (s[i] == c)
			return (s + i);
		i++;
	}
	if (c == '\0')
		return (s + i);
	return (0);
}

char	*ft_strrchr(const char *str, int c)
{
	char			*s;
	size_t			i;

	s = (char *)str;
	i = (ft_strlen(s));
	if (c == '\0')
		return (s + i);
	while (i > 0)
	{
		i--;
		if (s[i] == c)
			return (s + i);
	}
	return (0);
}

char	*ft_strdup(char *src)
{
	char	*new_src;
	int		src_l;
	int		i;

	src_l = ft_strlen(src);
	new_src = (char *)malloc(sizeof(char) * src_l + 1);
	if (!new_src)
		return (0);
	i = 0;
	while (src[i] != '\0')
	{
		new_src[i] = src[i];
		i++;
	}
	new_src[i] = '\0';
	return (new_src);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	char	*s;
	size_t	src_len;
	size_t	i;

	s = (char *)src;
	i = 0;
	src_len = ft_strlen(s);
	if (dstsize == 0)
		return (src_len);
	while (s[i] != '\0' && i < dstsize - 1)
	{
		dst[i] = s[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}

bool    ft_is_charset(char target, char const *set)
{
        while (*set)
        {
                if (target == *set)
                        return (true);
                ++set;
        }
        return (false);
}

char    *ft_strtrim(char const *s1, char const *set)
{
    char    *tmp;
    char    *s_1;
    char    *sett;
    int     i;  
    int     j;  

    if (!s1)
	    return (0);
    if (!set || !*set)
	    return ((char *)s1);
    s_1 = (char *)s1;
    sett = (char *)set;
    i = 0;
    j = ft_strlen(s_1);
    if (j < 1 || ft_strlen(sett) < 1)
        return (ft_strdup(""));
    while (ft_strchr(sett, s_1[i]) && i < j)
        i++;
    while (j > i && ft_strrchr(sett, s_1[j - 1]))
        j--;
    tmp = malloc(sizeof(char) * (j - i) + 1); 
    if (!tmp)
        return (0);
    ft_strlcpy(tmp, s_1 + i, (j - i) + 1);
    return (tmp);
}

int main(){
	char *a = ft_strdup("     test  test    ");
	char *res;

	res = ft_strtrim(a, NULL);
	printf("1: %s\n", res);
	free(res);

	res = ft_strtrim(a, NULL);
	printf("2: %s\n", res);
	free(res);
}