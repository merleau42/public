#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
int	main(void)
{
	int fd;
	fd = open("sample.txt", O_RDWR);
	write(fd,"\000 is nul:0\n", 11);
	write(fd,"\037 is unprintable:31\n", 20);
	write(fd,"\040 is printable:32\n", 18);
	write(fd,"\176 is printable:126\n", 19);
	write(fd,"\177 is del:127\n", 13);
	write(fd,"\377 is EOF:-1\n", 12);
	write(fd,"\376 is custom:-2\n", 15);
	write(fd,"\375 is custom:-3\n", 15);
}