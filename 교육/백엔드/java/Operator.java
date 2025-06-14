package chapter;

class OperatorExamples {
	public static void ex5() {
		int a = 10;
		int b = 4;

		// 사칙연산의 좌항이나 우항이 실수라면, 실수의 사칙연산이 됨. println은 소숫점 출력시 자리를 적당하게 잘라냄.
		System.out.println(a + " / " + b + " = " + (a / (float)b));
	}
	public static void ex6() {
		byte a = 100;
		byte b = 28;
		byte c = (byte)(a + b); // int미만의 사칙연산은 int형이 되므로 byte에 담을 수 없다 (자바식 형변환)

		System.out.println(c);
	}
	public static void ex9() {
		long a = 1_000_000 * 1_000_000;		// 숫자에 L,F 따위를 명시하지 않으면 int 형으로 취급됨
		long b = 1_000_000 * 1_000_000L;	// 숫자에 L을 명시하여, long 형으로 취급하여 연산이 이루어짐
		System.out.println("a=" + a);
		System.out.println("b=" + b);
	}
	public static void ex10() {
		int a = 1000000;

		int result1 = a * a / a;
		int result2 = a / a * a;

		System.out.printf("%d * %d / %d = %d\n", a, a, a, result1); // a*a 에서 오버플로우 발생
		System.out.printf("%d / %d * %d = %d\n", a, a, a, result2); // a/a 부터 계산되어서 오버플로우 예방
	}
	public static void ex13() {
		char c1 = 'a';
		char c2;
		char c3;

		// (1). 문자 리터럴 'a' 그 자체로는 char 형이지만, 상수이므로 컴파일중에 [97 + 1]로 대체됨. (전처리랑 비슷)
		// (2). 컴파일러는 실질적으로 [c2 = 97 + 1] 구문을 처리함.
		// (3). 98은 char 범위의 int 리터럴이므로, 암시적으로 char에 대입 가능
		c2 = 'a' + 1;
		System.out.println(c2);
		c3 = 98;
		System.out.println(c3);

		// (1). c2는 이미 char로 간주되므로, char + int가 되어 결과 타입은 int가 됨.
		// (2). int값을 char변수에 대놓고 할당하므로 오류 발생.
		/**
			c2 = c1 + 1;	// 에러
			System.out.println(c2);
		**/

		c2 = (char)(c1 + 1);
		System.out.println(c2);
		
		// char = int 구문에서, int가 리터럴이면 암시적으로 할당 가능
		// char = int 구문에서, int가 변수이면 명시적으로 선을 넘어버려서 불가능
		// 뷔페에서 남몰래 음식 싸가는 건 봐주는데, 대놓고 싸가는 건 안 봐줌.
	}
	public static void ex20() {
		System.out.println(-10%8);
		System.out.println((-10)%8);
		System.out.println(-(10%8));
		System.out.println(10%-8);
		System.out.println(-10%-8);
	}
	public static void ex24() {
		int x;
		char ch;

		x = 15;
		System.out.printf("10 < %d && %d < 20  ==  [%b]\n", x, x, // %b는 불리언
							10 < x && x < 20);

		x = 6;
		System.out.printf("%d%%2==0 || %d==3 && %d%%6!=0  ==  [%b]\n", x, x, x, // %b는 불리언
							x%2==0 || x==3 && x%6!=0); // AND와 OR중에서, 우선 순위가 높은 AND연산부터 함.

		ch = '1';
		System.out.printf("'0' <= '%c' && '%c' <= '9'  ==  [%b]\n", ch, ch, // %b는 불리언
							'0' <= ch && ch <= '9');

		ch = 'k';
		System.out.printf("'a' <= '%c' && '%c' <= 'z'  ==  [%b]\n", ch, ch, // %b는 불리언
							'a' <= ch && ch <= 'z');
	}
	public static void ex25() {
		double	pi	= 3.141592; // 소수 리터럴은 기본적으로 double 객체
		float	pi2	= 3.141592f; // 소수가 float 임을 표시

		double shortPi = Math.round(pi * 1000)/1000.0;
		System.out.println(shortPi);
	}
	public static void ex26() {
 		char c = 77;
		System.out.println(c >> 15 >> 1);
		System.out.println(c >> 16);
		System.out.println(c >> 31 >> 1);
		System.out.println(c >> 32); // 자료형의 크기가 32비트 이하이므로, 16비트를 초월해서 31까지 쉬프트함

		// 비트 쉬프트를 수행하는 Barrel Shifter 라는 회로는, 31비트를 한번에 (1클럭만에) 이동시킬 수 있음
		// 32비트를 넘어가면 한번에 시프트할 수 없어서, [연산을 나눠서 수행하거나] [%32를 적용하고 수행하거나] 선택함
		int i = 7777;
		System.out.println(i >> 31 >> 1);
		System.out.println(i >> 32); // 자료형의 크기가 32비트 이하라면 %32를 적용하고 수행함

		long x = 777777;
		System.out.println(x >> 40); // 자료형의 크기가 32비트 초과하면 나누어서 수행함 (x >> 32 >> 8 처럼)
		System.out.println(x >> 63 >> 1);
		System.out.println(x >> 64);
	}
	public static void ex27() {
		int a = -765;

		System.out.println(a);
		System.out.println(  (1 + 2 * (a >> 31) ) * a  );
		
	}
	public static void main(String[] args) {
		ex27();
	}
}
