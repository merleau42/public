#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int main2()
{
	int fd;
	fd = open("sample.txt", O_RDWR);
	write(fd,"123\000456\177789\377abc\376def\375xyz",23);
}

int	main(void)
{
	int fd;
	int bytes;
	static char buff[100];

	fd = open("sample.txt", O_RDWR);
	bytes = read(fd, buff, 100);

	for (int i=0; i<23; i++)
		printf("%d:%c\n", buff[i], buff[i]);
	printf("%d", bytes);
}

