package pkgs;

class Shape {
	String color = "black"; // 검은색이 기본값으로 상속됨
    void draw() { System.out.printf("도형:  색상(%s)\n", color); }
}

class Point {
    int x, y;

    Point(int x, int y) { this.x=x; this.y=y; }
    Point() { this(0, 0); }
    String get() { return "(" + x + ", " + y + ")"; }
}

// 원은 원점과 반지름으로 이루어짐
class Circle extends Shape {
    Point center; // 원점도 좌표의 일종이므로, 좌표 객체를 활용함
    int r;

    Circle(Point center, int r) {
        this.center = center;
        this.r = r;
    }

    Circle() { this(new Point(), 0); }

    void draw() {
        System.out.printf("원:  색상(%s),   원점(%d, %d),   반지름(%d)\n",
                                color,    center.x, center.y,   r);
    }
}

// 삼각형은 3개의 꼭지점으로 이루어짐
class Triangle extends Shape {
    Point[] ppp = new Point[3]; // 꼭지점도 좌표의 일종이므로, 좌표 객체를 활용함

    Triangle(Point[] ppp) { this.ppp = ppp; }

    void draw() {
        System.out.printf("삼각형:  색상(%s),   꼭지점%s, 꼭지점%s, 꼭지점%s\n",
                                   color,   ppp[0].get(), ppp[1].get(), ppp[2].get());
    }
}
