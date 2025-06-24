package chapter;
import java.util.*; // Array 클래스를 사용하기 위해 추가

class ArrayExamples {
	static void ex1() {
		int[] arr1 = new int[8];
		System.out.println("변경전: " + arr1.length);

		for (int i=0; i<arr1.length; i++) {
			arr1[i] = i + 1;
			System.out.println("arr1[" + i + "] = " + arr1[i]);
		}

		int[] arr2 = new int[arr1.length * 2];
		System.out.println("변경후: " + arr2.length);

		for (int i=0; i<arr1.length; i++)
			arr2[i] = arr1[i];

		for (int i=0; i<arr2.length; i++)
			System.out.println("arr2[" + i + "] = " + arr2[i]);
	}

	static void ex2() {
		char[] result =	{'A', 'B', 'C', 'D', '0', '1', '2',
						 '3', '4', '5', '6', '7', '8', '9'};
		char[] reverse = new char[result.length];
		
		for (int i=0;  i<reverse.length;  i++)
			reverse[i] = result[reverse.length - i - 1];
		
		for (int i=0; i<reverse.length; i++)
			System.out.println( result[i] );
	}

	static void ex3() {
		int[] score = {79, 88, 91, 33, 30, 33, 100, 55, 95};
		
		int max = score[0];
		int min = score[0];

		for (int i=0; i<score.length; i++) {
			if (score[i] > max)
				max = score[i];
			if (score[i] < min)
				min = score[i];
		}

		System.out.println( "최댓값: " + max );
		System.out.println( "최솟값: " + min );
	}

	static void ex4() {
		int choose = 45;
		int[] numArr = new int[choose];

		for (int i=0; i<numArr.length; i++) {
			numArr[i] = i;
			System.out.print( numArr[i] );
		}
		System.out.println();

		for (int i=0; i<100; i++) {
			int n = (int) (Math.random() * choose);
			int swap = numArr[0];
			numArr[0] = numArr[n];
			numArr[n] = swap;
		}
		
		for (int i=0; i<numArr.length; i++)
			System.out.print( numArr[i] + " " );
	}

	static void ex5() {
		int[] ball = new int[45];

		for(int i=0; i<ball.length; i++)
			ball[i] = i + 1;

		int temp = 0;
		int j = 0;

		for (int game=1; game<=5; game++){
			for (int i=0; i<6; i++) {
				j = (int) (Math.random() * 45);
				temp = ball[i];
				ball[i] = ball[j];
				ball[j] = temp;
			}

			System.out.printf("[%2d, %2d, %2d, %2d, %2d, %2d]\n",
				ball[0], ball[1], ball[2], ball[3], ball[4], ball[5]);
		}
	}

	static void ex6() {
		int[] code = {-4, -1, 3, 6, 11};
		int[] arr = new int[10];

		for (int i=0; i<arr.length; i++)
			arr[i] = code[ (int)(Math.random()*code.length) ];

		System.out.println(Arrays.toString(arr));
	}

	static void ex7() {
		String[] names = {"Kim", "Park", "Yi"};

		for (int i=0; i<names.length; i++) {
			System.out.println("names[" + i + "] = " + names[i]);
		}

		String tmp = names[2];
		System.out.println("tmp = " + tmp);
		names[0] = "Yu";

		for (String str : names)
			System.out.println(str);
	}
	
	static void ex8() {
		String animal = "dog,cat,bear";
		String[] arr = animal.split(",");
		
		for (String str : arr)
			System.out.println(str);
				
		for (int i=0; i<arr.length; i++)
			System.out.println("arr[" + i + "] == " + arr[i]);
		
	}

	static void ex13() {
		// 자료형[] 배열명 = {'원', '소', '나', '열'};
		char[] hex = {'C','A','F','E'};

		String[] binary =  {"0000", "0001", "0010", "0011",
							"0100", "0101", "0110", "0111",
							"1000", "1001", "1010", "1011",
							"1100", "1101", "1110", "1111"};

		String result = "";
		
		for (int i=0; i<hex.length; i++) {
			if ('0' <= hex[i] && hex[i] <= '9')
				result += binary[ hex[i] - '0' ];

			if ('A' <= hex[i] && hex[i] <= 'F')
				result += binary[ hex[i] + 10 - 'A' ];
			
			result += " ";
		}

		System.out.println("hex:     " + new String(hex));
		System.out.println("binary:  " + result);
	}

	static void ex14() {
		String src = "ABCDE";

		for(int i=0; i<src.length(); i++) {
			char ch = src.charAt(i);
			System.out.println("src.charAt(" + i + ") == " + ch);
		}

		char[] chArr = src.toCharArray();
		System.out.println(Arrays.toString(chArr));
	}

	static void ex15() {
		char[] chArr = {'A', 'B', 'C', 'D', 'E'};
		
		String src = "";
		
		for (char ch : chArr)
			src += ch;
		
		System.out.println(src);
	}

	static void ex16() {
		String source = "SOSHELP";

		String[] morse = {".-", "-...", "-.-.", "-..", ".",
						  "..-.", "--.", "....", "..", ".---",
						  "-.-", ".-..", "--", "-.", "---",
						  ".--.", "--.-", ".-.", "...", "-",
						  "..-", "...-", ".--", "-..-", "-.--", "--.."};

		String result = "";

		for (int i=0; i<source.length(); i++)
			result += morse[source.charAt(i) - 'A'] + " ";

		System.out.println(result);
	}

	static void main2(String[] args) {
		System.out.println(args.length);
		if (args.length > 0) {
			System.out.println(args[0]);
			System.out.println(args[1]);
			System.out.println(args[2]);
		}
	}

	static void ex17() {
		int[][] arr = { {1,2,3}, {4,5,6} };

		for (int[] i : arr) // arr의 원소로서, i는 int 배열이다
			for (int j : i) // i의 원소로서, j는 int 값이다
				System.out.println( j );
	}

	static void ex18() {
		String[] bingo = new String[10];
		
		for (String row : bingo)
//			row = "" + (long) (Math.random()*10000000000L);
			row = "4";

		for (String row : bingo)
			System.out.println( row );
	}

	static void ex19() {
		final int SIZE = 10;
		char[][] bingo = new char[SIZE][SIZE];
		
		for (int i=0; i<SIZE; i++)
			for (int j=0; j<SIZE; j++)
				bingo[i][j] = (char) (Math.random()*10 + '0');

		while (true) {
			System.out.printf( "숫자를 입력해주세요>" );
			Scanner sc = new Scanner(System.in);
			char target = (char)(sc.nextInt() + '0');
			
			System.out.println( target + "을 표시합니다." );
			
			for (int i=0; i<SIZE; i++)
				for (int j=0; j<SIZE; j++)
					if (bingo[i][j] == target)
						bingo[i][j] = '■';

			for (char[] row : bingo) {
				for (char col : row)
					System.out.printf( "%c", col );
				System.out.printf( "\n" );
			}
		}
	}

	static void 행렬곱() {
		int[][] a = {	{1, 2, 3},
						{4, 5, 6}	};

		int[][] b = {	{1, 2},
						{3, 4},
						{5, 6}		};

		final int ROW = a.length;
		final int COL = b[0].length;
		int[][] c = new int[ROW][COL];

		for (int i=0; i<ROW; i++)
			for (int j=0; j<COL; j++)
				for (int k=0; k<b.length; k++)
					c[i][j] += a[i][k] * b[k][j];

		for (int[] row : c) {
			for (int col : row)
				System.out.printf( "%d ", col );
			System.out.printf( "\n" );
		}

	}

	public static void main(String[] args) {
		행렬곱();
	}

}
