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

	public static void main(String[] args) {
		ex7();
	}
}
