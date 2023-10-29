#include <iostream>
using namespace std;

int arr[5] = { 3, 0, 0, 0, 0 };

int main() {
	for (int i = 1; i <= 4; i++)
		arr[i] = 2 * arr[i - 1] - 4;
	printf("%d", arr[4]);
}
