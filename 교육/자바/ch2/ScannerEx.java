package ch2;

import java.util.*; // Scanner 클래스를 사용하기 위해 추가

class ScannerEx {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in); // Scanner 클래스의 객체 생성

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
}
