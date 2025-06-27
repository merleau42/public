package pkgs;

import practice.Flow;

class Main {
	static void status(Tv t) {
		System.out.println(t.name + "의 색상은 " + t.color + " 입니다.");
		System.out.println(t.name + "의 채널은 " + t.channel + " 입니다.");
		if (t.power)
			System.out.println(t.name + "의 파워는 ON 입니다.");
		else 
			System.out.println(t.name + "의 파워는 OFF 입니다.");

		System.out.println();
	}

	static void ex1() {
		Tv t3 = new Tv();
			t3.color = "red";
			t3.name = "T3";
			t3.channel = 10;
			t3.channelUp();
			t3.channelUp();

		Tv t4 = new Tv();
			t4.color = "green";
			t4.name = "T4";
			t4.power();
			t4.channel = 10;
			t4.channelDown();
			t4.channelDown();

		status(t3);
		status(t4);
	}

	static void ex2() {
		Tv[] tvArr = new Tv[3]; // Tv의 배열만 생성되었고, Tv자체는 생성되지 않았음.

		for (int i=0; i<tvArr.length; i++) {
			tvArr[i] = new Tv();
			tvArr[i].name = "TV-" + (i+1);
			tvArr[i].channel = i + 10;
			System.out.println(tvArr[i].name + " 채널:  " + tvArr[i].channel);
		}
		System.out.println();

		for (int i=0; i<tvArr.length; i++) {
			tvArr[i].channelUp();
			tvArr[i].channelUp();
			tvArr[i].channelUp();
			System.out.println(tvArr[i].name + " 채널:  " + tvArr[i].channel);
		}
	}

	static void ex3() {
		Time t1 = new Time();

		t1.setHour(12);
		t1.setMinute(59);
		t1.setSecond(59);

		System.out.printf("%d시 %d분 %d초 입니다\n",
					t1.getHour(), t1.getMinute(), t1.getSecond());
	}

	static void ex4() {
		Card cd1 = new Card();
		cd1.kind = "하트";
		cd1.number = 7;
		cd1.getMembers();

		Card cd2 = new Card();
		cd2.kind = "클로버";
		cd2.number = 4;
		cd2.getMembers();

		cd1.width = 300;
		cd1.getMembers();
		cd2.getMembers();

		Card.width = 777;
		cd1.getMembers();
		cd2.getMembers();
	}

	static void ex5() {
		Calc sh = new Calc();

		int		result1 = sh.add( 5, 3 );
		int		result2 = sh.substract( 5, 3 );
		int		result3 = sh.multiply( 5, 3 );
		float	result4 = sh.divide( 5, 3 );

		System.out.println( result1 );
		System.out.println( result2 );
		System.out.println( result3 );
		System.out.println( result4 );
	}

	static void f1() {
		System.out.println("   ㄴf1() 시작");
		f2();
		System.out.println("   ㄴf1() 종료");
	}

	static void f2() {
		System.out.println("      ㄴf2() 시작");
		System.out.println("      ㄴf2() 종료");
	}

	public static void main2(String[] args) {
		System.out.println("main() 시작");
		f1();
		System.out.println("main() 종료");
	}

	public static void main3(String[] args) {
		Flow fl = new Flow();
		fl.ex2();
	}

	static void ex6() {
		final int SIZE = 13;
		int[] a = new int[SIZE];

		for (int i=0; i < a.length; i++)
			a[i] = (int)(Math.random()*SIZE) - 5;

		Tools arrayTools = new Tools();

		arrayTools.arr_print(  a  );
		arrayTools.arr_print(  arrayTools.arr_sort( a )  );
		System.out.println(  arrayTools.arr_sum( a )  );
		System.out.printf(  "%.2f\n", arrayTools.arr_average( a )  );
	}

	static void ex7() {
		Calc cc = new Calc();

		int[] w = {1, 2, 3, 4, 5};

		for (int i : w)
			System.out.println( cc.power(2, i) );

		for (int i=1; i<10; i++)
			System.out.println( cc.factorical(i) );
	}

	static Container copy(Container original) {
		Container clone = new Container();
		clone.x = original.x;
		clone.y = original.y;
		return clone;
	}

	static void ex8() {
		CaptionTv ctv = new CaptionTv();

		System.out.println("자막 사용: " + ctv.caption);
		ctv.displayCaption("자막 테스트1");

		ctv.caption = true;
		System.out.println("자막 사용: " + ctv.caption);
		ctv.displayCaption("자막 테스트2");
	}

	static void ex9() {
		Shape sp = new Shape();
		Point p1 = new Point();
		Point p2 = new Point(5, 12);
		Circle c1 = new Circle();
		Circle c2 = new Circle(new Point(7, 7), 10);

		Point[] ppp = {new Point(1,1), new Point(2,2), new Point(3,3)};
		Triangle t1 = new Triangle(ppp);

		sp.draw();
		c1.draw();
		c2.draw();
		t1.draw();
	}

	static void ex10() {
		Data1 d1 = new Data1();
		Data2 d2 = new Data2(20);
		Data2 d3 = new Data2();

		System.out.println(d2.value);
		System.out.println(d3.value);
	}

	static void ex11() {
		Car c1 = new Car();
		c1.color = "white";
		c1.gearType = "auto";
		c1.door = 4;

		Car c2 = new Car("black", "auto", 6);

	}

	public static void main(String[] args) {
		ex11();
	}

}
