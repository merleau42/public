package chapter;

public class PrintExamples {
    public static void ex1() {
        System.out.println("Hello, Java");
    }
    public static void ex2() {
        byte b = 1;
        short s = 2;
        char c = 'A';

        int finger = 10;
        long big = 100_000_000_000L;
        long hex = 0xFFFF_FFFF_FFFF_FFFFL;

        int octNum = 010;
        int hexNum = 0x10;
        int binNum = 0b10;

        System.out.printf("b=%d%n", b);
        System.out.printf("s=%d%n", s);
        System.out.printf("c=%c, %d %n", c, (int)c);
        System.out.printf("finger=[%5d]%n", finger);
        System.out.printf("finger=[%-5d]%n", finger);
        System.out.printf("finger=[%05d]%n", finger);
        System.out.printf("big=%d%n", big);
        System.out.printf("hex=%#x%n", hex);
        System.out.printf("octNum=%o, %d%n", octNum, octNum);
        System.out.printf("hexNum=%x, %d%n", hexNum, hexNum);
        System.out.printf("binNum=%s, %d%n", Integer.toBinaryString(binNum), binNum);
    }
    public static void ex3() {
        String url = "www.codechobo.com";

        float f1 = .10f;
        float f2 = 1e1f;
        float f3 = 3.14e3f;
        double d = 1.23456789;

        System.out.printf("f1=%f, %e, %g%n", f1, f1, f1);
        System.out.printf("f1=%f, %e, %g%n", f2, f2, f2);
        System.out.printf("f1=%f, %e, %g%n", f3, f3, f3);
        System.out.printf("f1=%f, %e, %g%n", d, d, d);
    }
	public static void ex4() {
		System.out.println('\'');		// ''' 대신 '''를 출력.
		System.out.println("abc\t123\b456");	// 탭과 백스페이스
		System.out.println('\n');		// 개행문자 출력하고 개행
		System.out.println("\"Hello\"");	// 큰따옴표 출력
		System.out.println("c:\\");		// 역슬래쉬 출력
	}
    public static void main(String[] args) {
        ex2();
    }
}
