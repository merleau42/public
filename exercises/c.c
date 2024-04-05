#include <stdio.h>
#include <string.h>

int	main(void)
{
	char buf[1 + 13 * 2];
	int i;

	i = -1;
	while(++i + 'a' <= 'z')
		buf[i] = i + 'a';
	buf[i] = 0;
	printf("%s", buf);
	return (0);
}
