#include <bits/stdc++.h>
using namespace std;
// https://www.acmicpc.net/problem/11399


// 전역 변수: 변수나 배열의 값이 자동으로 0으로 초기화
int duration[1000];

int main(){
	//입력 받기
	int n;
	cin >> n;

	for (int i=0; i<n; i++) {
		cin >> duration[i]; // 3 1 4 3 2
	}

	sort(duration, duration+n);

	int sum=0;
	int current=0;
	for (int i=0; i<n; i++) {
		current += duration[i];
		sum += current;
	}

	cout << sum;

	return 0;
}

