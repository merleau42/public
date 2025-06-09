package ch2;

public class SpecialCharEx {
	public static void main(String[] args) {
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
}
