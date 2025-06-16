package chapter;

class FlowExamples {
	static void ex1() {
        for(int i=1, j=9;  i<=9;  i++, j--)
            System.out.printf("i=%d, j=%d\n", i, j);
	}
    static void ex2() {
        for(int i=1; i<=9; i++){
            for(int j=2; j<=9; j++)
                System.out.printf("%d x  %d = %2d\t", j, i, j*i);
            System.out.printf("\n");
        }
	}
	public static void main(String[] args) {
		ex2();
	}
}
