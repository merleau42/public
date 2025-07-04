package pkgs;

class Calc {
	// static으로 선언한다면, 인스턴스 생성 없이 클래스 이름만으로도 메소드 호출 가능
	static int add(int a, int b) { return a + b; }
	static int substract(int a, int b) { return a - b; }
	static int multiply(int a, int b) { return a * b; }
	static float divide(float a, float b) { return a / b; }

	static int factorical(int n) {
		if (n <= 1)
			return 1;
		return n * factorical(n-1);
	}
	
	static int factorical_iter(int n) {
		int result = 1;
		for (int i=1; i<=n; i++)
			result *= n;
		return result;
	}

	static int power(int a, int n) {
		if (n == 0)
			return 1;
		return a * power(a, n-1);
	}
}
