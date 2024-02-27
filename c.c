#include <unistd.h>

int main(){
    int b, c;

    b = 1734697332;
    c = 1735287147;
    write(1, &b, 4);
    write(1, &c, 4);
}