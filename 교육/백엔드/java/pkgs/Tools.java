package pkgs;

class Tools {
	static void arr_print(int[] arr) {
		System.out.printf("[ ");
		for(int e : arr)
			System.out.printf("%d, ", e);
		System.out.printf("\b\b ]\n");
	}

	static int arr_sum(int[] arr) {
		int sum = 0;
		for(int e : arr)
			sum += e;
		return sum;
	}

	static float arr_average(int[] arr) {
		return (float) arr_sum(arr) / arr.length;
	}

	static int[] arr_sort(int[] arr) {
		int tmp;
		for (int wave=0; wave < arr.length; wave++)
			for (int i=wave; i < arr.length; i++)
				if (arr[wave] > arr[i]) {
					tmp = arr[wave];
					arr[wave] = arr[i];
					arr[i] = tmp;
				}

		return arr;
	}
}
