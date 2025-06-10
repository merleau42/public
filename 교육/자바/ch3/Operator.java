package ch2;

class OperatorExamples {
	public static void main(String[] args) {
		ex13();
	}
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
	public static void ex13(){
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
		c2 = c1 + 1;	// 에러
		System.out.println(c2);

		c2 = (char)(c1 + 1);
		System.out.println(c2);
		

		// char = int 구문에서, int가 리터럴이면 암시적으로 할당 가능
		// char = int 구문에서, int가 변수이면 명시적으로 선을 넘어버려서 불가능
		// 뷔페에서 남몰래 음식 싸가는 건 봐주는데, 대놓고 싸가는 건 안 봐줌.
	}
}
