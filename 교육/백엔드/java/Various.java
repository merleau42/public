package ch2;

public class VariousExamples {

	public static void ex1() {
		int year = 0;
		int age = 14;
		// TODO 자동 생성된 메소드 스텁

		System.out.println(year);
		System.out.println(age);
		
		year = 2000 + age;
		age = age + 1;
		
		System.out.println(year);
		System.out.println(age);
	}

	public static void ex2() {
        short sMin = -32768;
        short sMax = 32767;
        short s = 777;

        char cMin = 0;
        char cMax = 65535;

        System.out.println("short:\t" + s);
        System.out.println("제자리:\t" + s + " - 65536 = " + (short)(s - 65536));
        System.out.println("제자리:\t" + s + " + 65536 = " + (short)(s + 65536));
        System.out.println();

        System.out.println("sMin\t=\t" + sMin);
        System.out.println("sMin-1\t=\t" + (short)(sMin - 1));
        System.out.println("sMin-1\t=\t" + (sMin - 1)); // 컴파일러가 자동으로 형변환
        System.out.println();

        System.out.println("sMax\t=\t" + sMax);
        System.out.println("sMax+1\t=\t" + (short)(sMax + 1));
        System.out.println("sMax+1\t=\t" + (sMax + 1)); // 컴파일러가 자동으로 형변환
        System.out.println();

        System.out.println("cMin\t=\t" + (int)cMin);
        System.out.println("--cMin\t=\t" + (int)--cMin);
        System.out.println();

        System.out.println("cMax\t=\t" + (int)cMax);
        System.out.println("++cMax\t=\t" + (int)++cMax);
	}
	public static void ex3() {
		float   f   =   9.12345678901234567890f;	// 21자리
		System.out.printf("21자	:	12345678901234567890\n");
		System.out.printf("f	:	%f --- %s%n", f, "소숫점 6자리 이후 정밀도가 떨어짐");
		System.out.printf("f	:	%24.20f%n", f);
	}
	public static void ex4() {
		float f = 9.1234567f;
		int i = Float.floatToIntBits(f);

		System.out.printf("%f\n", f);
		System.out.printf("10진수:	%d\n", i);
		System.out.printf(" 2진수:	%s\n", Integer.toBinaryString(i));
		System.out.printf("16진수:	%x\n", i);
	}
    public static void ex5() {
        byte x = 127;		//	-128 ~ +127
        short y = 32767;	//	-32768 ~ +32767
        int z = 2147483647;	//	2^31 ~ (-2^31 + 1)
        long l = 9223372036854775807L;

        BigInteger a = new BigInteger("100000000000000000000000000000");
        BigInteger b = new BigInteger("999999999999999999999999999999");

        System.out.println(x);
        System.out.println(y);
        System.out.println(z);
        System.out.println(l);
        System.out.println(a);
        System.out.println(b);

		final int MAX_SPEED = 10;	// 상수
		int spare = MAX_SPEED + 10;

		System.out.println(spare);

		int x2 = 0b10;
		int x8 = 010;
		int x10 = 10;
		int x16 = 0x10;

		System.out.println(x2);
		System.out.println(x8);
		System.out.println(x10);
		System.out.println(x16);
    }
	public static void main(String[] args) {
		ex1();
	}

}
