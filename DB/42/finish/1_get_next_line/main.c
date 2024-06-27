#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main()
{
	int fd;
	// char buff[1111];
	char *line;

	fd = open("sample.txt", O_RDONLY);

	line = (char *)1;

	line = get_next_line(0);
	printf("%s", line);
	/*
	while(line)
	{
		line = get_next_line(fd);
		printf("%s", line);
	}*/
}
