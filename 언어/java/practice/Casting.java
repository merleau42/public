package chapter;

class CastingExamples {
	public static void main(String[] args) {
		ex4();
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
	public static void ex4() {
		// float형 = 가수 3바이트 (0 ~ 16777217) + 지수 1바이트
		// 16777217보다 작은 숫자인 0 ~ 9999999 즉, 7자리까지는 참값이 온전하게 저장됨.
		// int를 float형으로 저장할 경우, 7자리 참값의 보존이 보장됨.
		// 소수는 2진수의 무한소수로 나타내므로, 가수에 주어진 비트 용량이 빨리 소진됨. 
		// 가수 비트 한계로 인해 뒤쪽 자릿수는 근사되어 저장되며,
		// 결국 마지막 자릿수에서 오차가 발생.

		float i1 =  955577f;
		float i2 =  9555777f;
		float i3 =  95557777f;
		float i4 =  955577777f;

		float f1 =  9.55577f;
		float f2 =  9.555777f;
		float f3 =  9.5557777f;
		float f4 =  9.55577777f;

		// System.out.printf("오로지 정수:	%f\n", i1);
		// System.out.printf("오로지 정수:	%f\n", i2);
		// System.out.printf("오로지 정수:	%f\n", i3);
		// System.out.printf("오로지 정수:	%f\n", i4);

		// System.out.printf("소숫점 이하:	%f\n", f1);
		// System.out.printf("소숫점 이하:	%f\n", f2);
		// System.out.printf("소숫점 이하:	%f\n", f3);
		// System.out.printf("소숫점 이하:	%f\n", f4);

 		// 정확히 2진수로 나타낼 수 있어서, 가수부 3바이트를 낭비하지 않음
		// 실수이지만 7자리까지 표현됨
		float 참값1 = 1.4531256666f;
		float 참값2 = 2.4843756666f;
		float 참값3 = 3.0781256666f;
		float 참값4 = 4.0156256666f;
		float 참값5 = 5.0781256666f;

 		// 정확히 2진수로 나타낼 수 없어서, 가수부 3바이트로 부족함
		// 6자리 까지만 정확함
		float 오차1 = 1.4531256666f;
		float 오차2 = 2.4843726666f;
		float 오차3 = 3.0781236666f;
		float 오차4 = 4.0156246666f;
		float 오차5 = 5.0781256666f;

		System.out.printf("%f\n", 참값1);
		System.out.printf("%f\n", 참값2);
		System.out.printf("%f\n", 참값3);
		System.out.printf("%f\n", 참값4);
		System.out.printf("%f\n\n", 참값5);

		System.out.printf("%f\n", 오차1);
		System.out.printf("%f\n", 오차2);
		System.out.printf("%f\n", 오차3);
		System.out.printf("%f\n", 오차4);
		System.out.printf("%f\n", 오차5);
	}
	public static void ex5() {
        char ch = 'A';

        int code = (int)ch;
        System.out.printf("%c=%d(%#x)\n", ch, code, code);

        char hch = '가';
        System.out.printf("%c=%d(%#x)\n", hch, (int)hch, (int)hch);
	}
}
