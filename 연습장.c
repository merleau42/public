#include <unistd.h>

int main(){
    int a;
    a = 19033;

    // Y의 아스키코드는 89
    // J의 아스키코드는 74
    write(1, &a, 2);

    return 0;
}