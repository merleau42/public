package pkgs;

class Container {
    int x;
    int y;
    int z;

    // static void set(int x, int y, int z) {
    //     this.x = x;
    //     this.y = y;
    //     this.z = z;
    // }
}

class Data1 {
    int value;
    int x, y;
}

class Data2 {
    int value;
    Data2(int x) { value = x; }
    Data2() { value += 10; } // 생성자를 하나라도 정의하였다면, 기본_생성자() 도 직접 정의해야함
}