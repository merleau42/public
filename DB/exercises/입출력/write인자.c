#include <unistd.h>

//	./a.out > p 2> q
int main (int argc, char *argv[]){
	write(1, "aaaaa\n", 6);
	write(2, "bbbbb\n", 6);
	write(1, "ccccc\n", 6);
	write(1, "ddddd\n", 6);
	write(2, "eeeee\n", 6);
}
