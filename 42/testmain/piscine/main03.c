#include <stdio.h>
#include <string.h>
#include "../rendu/c03/ex00/ft_strcmp.c"
#include "../rendu/c03/ex01/ft_strncmp.c"
#include "../rendu/c03/ex02/ft_strcat.c"
#include "../rendu/c03/ex03/ft_strncat.c"
#include "../rendu/c03/ex04/ft_strstr.c"
#include "../rendu/c03/ex05/ft_strlcat.c"

int strlcat(char *dst, const char *src, int siz)
{
	char *d = dst;
	const char *s = src;
	int n = siz;
	int dlen;

	/* Find the end of dst and adjust bytes left but don't go past end */
	while (n-- != 0 && *d != '\0')
		d++;
	dlen = d - dst;
	n = siz - dlen;

	if (n == 0)
		return(dlen + strlen(s));
	while (*s != '\0') {
		if (n != 1) {
			*d++ = *s;
			n--;
		}
		s++;
	}
	*d = '\0';

	return(dlen + (s - src));	/* count does not include NUL */
}

int	main(void)
{
	char	dest[50], orig_dest[50];
	char	src[] = " world";

	// Test cases for ft_strcmp
	printf("===Testing ft_strcmp===\n");
	printf("Compare 'hello' and 'hello':\n");
	printf("ft_strcmp %d, strcmp: %d\n",
			ft_strcmp("hello", "hello"),
			strcmp("hello", "hello")); // Expected: 0
	printf("Compare 'hello' and 'world':\n");
	printf("ft_strcmp %d, strcmp: %d\n",
			ft_strcmp("hello", "world"),
			strcmp("hello", "world")); // Expected: Negative value
	printf("Compare 'world' and 'hello':\n");
	printf("ft_strcmp %d, strcmp: %d\n",
			ft_strcmp("world", "hello"),
			strcmp("world", "hello")); // Expected: Positive value
	printf("Compare 'hello' and 'hello world':\n");
	printf("ft_strcmp %d, strcmp: %d\n",
			ft_strcmp("hello", "hello world"),
			strcmp("hello", "hello world")); // Expected: Negative value

	// Test cases for ft_strncmp
	printf("\n===Testing ft_strncmp===\n");
	printf("Compare 'hello' and 'hello' for first 5 characters:\n");
	printf("ft_strncmp %d, strncmp: %d\n",
		ft_strncmp("hello", "hello", 5),
		strncmp("hello", "hello", 5)); // Expected: 0
	printf("Compare 'hello' and 'world' for first 3 characters:\n");
	printf("ft_strncmp %d, strncmp: %d\n",
		ft_strncmp("hello", "world", 3),
		strncmp("hello", "world", 3)); // Expected: Negative value
	printf("Compare 'world' and 'hello' for first 3 characters:\n");
	printf("ft_strncmp %d, strncmp: %d\n",
		ft_strncmp("world", "hello", 5),
		strncmp("world", "hello", 5)); // Expected: Positive value
	printf("Compare 'hello' and 'hello world' for first 7 characters:\n");
	printf("ft_strncmp %d, strncmp: %d\n",
		ft_strncmp("hello", "hello world", 7),
		strncmp("hello", "hello world", 7)); // Expected: Negative value
	printf("Compare 'hello' and 'hello world' for first 5 characters:\n");
	printf("ft_strncmp %d, strncmp: %d\n",
		ft_strncmp("hello", "hello world", 5),
		strncmp("hello", "hello world", 5)); // Expected: 0

	// Test cases for ft_strcat
	printf("\n===Testing ft_strcat===\n");
	strcpy(dest, "Hello");
	strcpy(orig_dest, "Hello");
	printf("Concatenate 'Hello' and ' world':\n");
	printf("ft_strcat: %s, strcat: %s\n",
		ft_strcat(dest, src),
		strcat(orig_dest, src)); // Expected: "Hello world"

	// Test cases for ft_strncat
	printf("\n===Testing ft_strncat===\n");
	strcpy(dest, "Hello");
	strcpy(orig_dest, "Hello");
	printf("Concatenate 'Hello' and ' world' for first 3 characters:\n");
	printf("ft_strncat: %s, strncat: %s\n",
		ft_strncat(dest, src, 3),
		strncat(orig_dest, src, 3)); // Expected: "Hello wo"

	// Test cases for ft_strstr
	printf("\n===Testing ft_strstr===\n");
	printf("Find 'world' in 'Hello world':\n");
	printf("ft_strstr: %s, strstr: %s\n",
		ft_strstr("Hello world", "world"),
		strstr("Hello world", "world")); // Expected: "world"
	printf("Find '' in 'Hello world':\n");
	printf("ft_strstr: %s, strstr: %s\n",
		ft_strstr("Hello world", ""),
		strstr("Hello world", "")); // Expected: "Hello world"
	printf("Find 'Hello' in 'Hello world':\n");
	printf("ft_strstr: %s, strstr: %s\n",
		ft_strstr("Hello world", "Hello"),
		strstr("Hello world", "Hello")); // Expected: "Hello world"
	printf("Find 'Bye' in 'Hello world':\n");
	printf("ft_strstr: %s, strstr: %s\n",
		ft_strstr("Hello world", "Bye"),
		strstr("Hello world", "Bye")); // Expected: (null)

	// Test cases for ft_strlcat
	printf("\n===Testing ft_strlcat===\n");
	strcpy(dest, "Hello");
	strcpy(orig_dest, "Hello");
	printf("Length after strlcat 'Hello' and ' world':\n");
	printf("ft_strlcat: %d, strlcat: %d, dest: %s\n",
		ft_strlcat(dest, src, 50),
		strlcat(orig_dest, src, 50),
		dest); // Expected: Length of "Hello world" = 11
	strcpy(dest, "Hello");
	strcpy(orig_dest, "Hello");
	printf("Length after strlcat 'Hello' and ' world' with size 9:\n");
	printf("ft_strlcat: %d, strlcat: %d, dest: %s\n",
		ft_strlcat(dest, src, 9),
		strlcat(orig_dest, src, 9),
		dest);
	strcpy(dest, "Hello");
	strcpy(orig_dest, "Hello");
	printf("Length after strlcat 'Hello' and ' world' with size 3:\n");
	printf("ft_strlcat: %d, strlcat: %d, dest: %s\n",
		ft_strlcat(dest, src, 3),
		strlcat(orig_dest, src, 3),
		dest);

	return (0);
}