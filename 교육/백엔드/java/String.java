package chapter;

class StringExamples {
	public static void ex1() {
		String s1 = "";
		String s2 = null;

		String str1 = "문자열";
		String str2 = "문자열";
		String str3 = new String("문자열");

		// 등호는 객체 사이에 주소를 비교함
		if (str1 == str2)
			System.out.println("같은 주소"); // String-리터럴 "문자열"을 똑같이 가리킴
		else
			System.out.println("다른 주소");

		if (str1 == str3)
			System.out.println("같은 주소");
		else
			System.out.println("다른 주소"); // new로 생성된 인스턴스는 새 주소를 가짐
		
		// equals는 객체 사이에 내용을 비교함
		if (str1.equals(str2))
			System.out.println("같은 내용"); // 각각의 문자를 일대일로 비교함
		else
			System.out.println("다른 내용");
	}
	public static void ex2() {
		String s1 = "abcd";
		String s2 = "ABCD";

		System.out.println("문자열[s1] :  " + s1);
		System.out.println("문자열[s2] :  " + s2);

		// compareTo는 문자열을 사전순으로 비교함
		if (s1.compareTo(s2) == 0)
			System.out.println("문자열 두 짝이 똑같아요");
		if (s1.compareTo(s2) < 0)
			System.out.println("문자열 s1이 앞섭니다");
		if (s1.compareTo(s2) > 0)
			System.out.println("문자열 s2가 앞섭니다");
		
		System.out.println(s1.compareTo(s2));
	}
	public static void ex3() {
		String s1 = "여러분~";
		String s2 = " 조금만 더 힘내세요!";

		// length는 문자열의 길이를 확인함
		s1 = s1.concat(s2);
		System.out.println(s1);
		System.out.println(s1.length());

		// replace는 다른 문자열로 대체함
		s2 = s2.replace("조금만", "많이");
		System.out.println(s2);

		// tirm은 앞뒤 공백을 제거함
		String a = "      123";
		String b = "   456   ";
		String c = "789   ab   ";
		System.out.println( a.trim() + b.trim() + c.trim() );
	}
	public static void ex4() {
		String str1 = "java자바";
		String str2 = "JAVA자바";

		if (str1.equalsIgnoreCase(str2))
			System.out.println("알파벳의 대소문자는 무시하고, 같은 문자열");

		System.out.println("원본: " + str2);
		System.out.println("변환: " + str2.toLowerCase());

		System.out.println("원본: " + str1);
		str1 = str1.toUpperCase(); // toUpperCase()의 결과값은 휘발되며 원본은 변경되지 않음. 대입 연산자로 붙잡기.
		System.out.println("변환: " + str1);

		System.out.println("str1: " + str1);
		System.out.println("str2: " + str2);

		if (str1.equals(str2))
			System.out.println("대문자로 같은 문자열");

		if (str2.toLowerCase().equalsIgnoreCase(str1)) //str2가 소문자가 되었지만.
			System.out.println("대소문자 무시하고 같은 문자열");		
	}
    public static void ex5() {
        String name = "Ja" + "Va";

        System.out.printf("%s\n", name);
        System.out.printf("%d\n", 1 + 1);
        System.out.printf("%s\n", "Ja" + "Va");
        System.out.printf("%s\n", "Java" + 1.0);
        System.out.printf("%s\n", 1 + "Java");

        System.out.println("" + 7);
    }
    public static String ex6(int zs, int x) {
        String zero = "00000000000000000000000000000000";

		return zero.substring(zero.length() - zs) + x;
    }
	public static void main(String[] args) {
		System.out.println( ex6(5, 7777) );
	}
}
