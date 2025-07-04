package pkgs;

abstract class Unit {
    int x, y;
    abstract void move(int x, int y);
    void stop() {System.out.println("현재 위치에 정지합니다.");}
}

class Marine extends Unit {
    Marine() {
        System.out.printf("마린 준비 완료.\n");
    }

    void move(int x, int y) {
        this.x += 6;
        this.y += 40;
    }

    void stimPack() {
        y -= 10;
    }
}

class Tank extends Unit {
    Tank() {
        System.out.printf("탱크 준비 완료.\n");
    }

    void move(int x, int y) {
        this.x += 30;
        this.y += 150;
    }

    void changeMode() {
        x += 40;
    }
}

class Dropship extends Unit {
    void move(int x, int y) {
        this.x = x;
        this.y += 120;
    }
    void load() {
        System.out.println("지정된 대상을 태웁니다.");
    }
    void unload() {
        System.out.println("로딩중...");
    }
}
