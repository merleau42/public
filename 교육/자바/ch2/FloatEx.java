package ch2;

class FloatExample {
	public static void main(String[] args) {
		// FloatEx1();
		FloatToBinEx();
	}
	public static void FloatEx1() {
		float   f   =   9.12345678901234567890f;	// 21자리
		System.out.printf("21자	:	12345678901234567890\n");
		System.out.printf("f	:	%f --- %s%n", f, "소숫점 6자리 이후 정밀도가 떨어짐");
		System.out.printf("f	:	%24.20f%n", f);
	}
	public static void FloatToBinEx() {
		float f = 9.1234567f;
		int i = Float.floatToIntBits(f);

		System.out.printf("%f\n", f);
		System.out.printf("10진수:	%d\n", i);
		System.out.printf(" 2진수:	%s\n", Integer.toBinaryString(i));
		System.out.printf("16진수:	%x\n", i);
	}
}
