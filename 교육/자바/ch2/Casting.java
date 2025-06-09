package ch2;

class CastingExamples {
	public static void main(String[] args) {
		ex3();
	}
	public static void ex1() {
		double d = 85.4;
        int score = (int) d;

		System.out.printf("d	:	%f\n", d);
		System.out.printf("score	:	%d\n", score);
	}
	public static void ex2() {
		int i;
		byte b;

		i = 10;
		b = (byte) i;
		System.out.printf("[int -> byte]  i=%d -> b=%d\n", i, b);

		i = 300;
		b = (byte) i;
		System.out.printf("[int -> byte]  i=%d -> b=%d\n", i, b);

		b = 10;
		i = (int) b;
		System.out.printf("[byte -> int]  b=%d -> i=%d\n", b, i);

		b = -2;
		i = (int) b;
		System.out.printf("[byte -> int]  b=%d -> i=%d\n", b, i);
		System.out.println("i=" + Integer.toBinaryString(i));
	}
	public static void ex3() {
		float f		= 9.1234567f; // 할당할 때 부터, 이미 정밀도가 손실된 상태 (6자리 초과)
		double d	= 9.1234567; // 원래 값을 그대로 보존
		double d2	= (double)f; // 이미 손실된 값을 큰 그릇에 담아도 원래 값이 되지 않음

		System.out.printf("f	:	%20.18f\n", f);
		System.out.printf("d	:	%20.18f\n", d);
		System.out.printf("d2	:	%20.18f\n", d2);
	}
}
