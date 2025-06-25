package practice;
import java.util.*; // Scanner 클래스를 사용하기 위해 추가

public class Flow {
	public static void ex1() {
        for(int i=1, j=9;  i<=9;  i++, j--)
            System.out.printf("i=%d, j=%d\n", i, j);
	}
    public static void ex2() {
        for(int i=1; i<=9; i++){
            for(int j=2; j<=9; j++)
                System.out.printf("%d x  %d = %2d\t", j, i, j*i);
            System.out.printf("\n");
        }
	}
    public static void ex3() {
        for (int i=0; i<=23; i++)
            for (int j=0; j<=59; j++)
                for (int k=0; k<=59; k++)
                    System.out.printf("%02d:%02d:%02d\n", i, j, k);
	}
    public static void ex4() {
        int i = 11;
        System.out.println("카운트 다운을 시작합니다.");
        while(i-- > 0) {
            System.out.println(i);
            for(long j=0; j<1000000000L; j++);
        }
        System.out.println("땡!");
	}
    public static void ex5() {
        int i=0;
        int sum=0;

        while( (sum += ++i) <= 100 ) {
            System.out.println(i + "\t" + sum);
        }
	}
    public static void ex6() {
        int input, answer;
        Scanner sc = new Scanner(System.in);
        
        answer = (int)(Math.random()*100) + 1;
        do {
            System.out.print("1~100 사이의 값을 입력하세요 : ");
            input = sc.nextInt();
            if (input > answer) 
                System.out.println("더 작은 수를 입력하세요.");
            else if (input < answer)
                System.out.println("더 큰 수를 입력하세요.");
        } while (input != answer);
        System.out.println("정답입니다!");
	}
    public static void ex7() {
        for(int i=1; i<=333; i++){
            System.out.printf("%d: ", i);

            int tmp = i;
            do {
                if (tmp%10%3 == 0  &&  tmp%10!=0)
                    System.out.printf("짝");
            } while( (tmp/=10) != 0 );

            System.out.printf("\n");
        }
	}
    public static void ex8() {
        Scanner sc = new Scanner(System.in);
        String items = "[장바구니]: ";
        int price = 0;

        while(true) {
            System.out.printf("(1) 아메리카노 : 3,500원\n");
            System.out.printf("(2) 카페라떼 : 4,500원\n");
            System.out.printf("(3) 카푸치노 : 4,200원\n");
            System.out.printf("(4) 카페모카 : 4,500원\n");
            System.out.printf("(5) 헤이즐넛 : 4,800원\n");
            System.out.printf("(0) 종료\n");

            System.out.printf("원하시는 메뉴를 선택하세요 >");
            int menu = sc.nextInt();

            if (menu == 0){
                System.out.printf("프로그램을 종료합니다.");
                break;
            }
            else if (menu <= 5){
                if (menu == 1)  {price += 3500; items += "아메리카노, "; }
                if (menu == 2)  {price += 4500; items += "카페라떼, "; }
                if (menu == 3)  {price += 4200; items += "카푸치노, "; }
                if (menu == 4)  {price += 4500; items += "카페모카, "; }
                if (menu == 5)  {price += 4800; items += "헤이즐넛, "; }
                System.out.printf("\033[H\033[2J"); // 콘솔 지우기
                System.out.printf("%s\n", items);
                System.out.printf("결제하실 금액은 [ %d원 ] 입니다.\n", price);
            }
            else {
                System.out.printf("\033[H\033[2J"); // 콘솔 지우기
                System.out.printf("%s\n", items);
                System.out.printf("메뉴를 잘못 선택하였습니다.\n");
            }
        }
	}
	public static void main(String[] args) {
		ex8();
	}
}
