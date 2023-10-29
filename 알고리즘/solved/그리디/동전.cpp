#include <bits/stdc++.h>
using namespace std;
// https://www.acmicpc.net/problem/11047


// 전역 변수: 변수나 배열의 값이 자동으로 0으로 초기화


int c[10]; //동전 리스트

int main(){
	//입력 받기
	int n, k;
	cin >> n >> k;

	for (int i=0; i<n; i++) {
		cin >> c[i];

		if (c[i]>k)
			c[i] = 0; // 쓸 수 있는 동전만 받기
	}

	int sum=0;
	for (int i=n-1; i>=0; i--){ // 큰 동전부터 순회  c[n-1] ~ c[0]
		if (c[i]) { // 쓸 수 있는 동전이면
			sum += k / c[i];      // 해당 동전의 사용 횟수 합산
			   k = k % c[i];
		}
	}

	cout << sum;

	return 0;

}