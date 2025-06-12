package chapter;

import java.util.*; // Scanner 클래스를 사용하기 위해 추가

class ScannerExamples {
	static Scanner sc = new Scanner(System.in);
	static void ex1() {
		System.out.print("첫번째 정수를 입력해주세요.>");
		String input1 = sc.nextLine();

		System.out.print("두번째 정수를 입력해주세요.>");
        String input2 = sc.nextLine();

		int num1 = Integer.parseInt(input1);
		int num2 = Integer.parseInt(input2);

		System.out.printf("더하기 = %d%n", num1 + num2);
		System.out.printf("빼기 = %d%n", num1 - num2);
		System.out.printf("곱하기 = %d%n", num1 * num2);
		System.out.printf("나눗셈 = %f%n", (float)num1 / num2);
	}
	static void ex2() {
		System.out.printf("문자열을 입력하세요.>");
		String input = sc.nextLine();

		char ch;
		ch = input.charAt(0);

		if ('0' <= ch && ch <= '9')
			System.out.printf("첫글자는 숫자입니다.\n");
		
		else if ( ('a' <= ch && ch <= 'z') || ('A' <= ch && ch <= 'Z') )
			System.out.printf("첫글자는 알파벳입니다.\n");

		else 
			System.out.printf("입력하신 문자는 한글이거나 특수문자입니다.\n");
	}
	public static void main(String[] args) {
		ex2();
	}
}
