package ch2;

import java.math.BigInteger;

public class Exam01 {
    public static void main(String[] args) {
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
}
