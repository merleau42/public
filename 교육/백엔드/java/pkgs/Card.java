package pkgs;

class Card {
	// static: 모든 인스턴스에 적용되는 값. 이미 생성된 인스턴스에도 변경 사항이 적용됨.
	static int width = 100;
	static int height = 250;

	String kind;
	int number;

	void getMembers() {
		System.out.printf("[%s%d] %dw, %dh\n", kind, number, width, height);
	}
}
// ㄴㅇㅎㅂㄹㄱ
