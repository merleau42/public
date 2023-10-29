#include <bits/stdc++.h>
using namespace std;
// https://www.acmicpc.net/problem/2293


// 전역 변수: 변수나 배열의 값이 자동으로 0으로 초기화
int n, k;
int f[10001];

int main(){
	//입력 받기
	cin >> n >> k;


	//수열의 일부를 하드 코딩해서 점화식의 재료로 사용
	int c;
	cin >> c;

	for (int i=1; i<=k; i++) {
		if (i%c==0)
			f[i] = 1;
	}

	f[0]=1;

	//점화식을 활용해서 배열의 나머지 빈 칸을 채우기
	for (int i=1; i<n; i++) {
		cin >> c;

		for (int j=1; j<=k; j++) {
			if (j-c >= 0){
				f[j] += f[j-c];
			} 
		}

	}

	cout << f[k];


	return 0;
}



// DP 개념 자체는 재귀 호출이랑 무관하다
// 도미노를 통해서 치역의 나머지 빈 칸을 (배열) 채워나가기
// 이미 알고있는 결과값을 참고해서 새로운 결과값의 연산을 줄임

/*
반복문:
	분기1 ㅡ 점화식 하위 요소가 불가능하면 F(x) = 불가능
	분기2 ㅡ 점화식 일부 요소가 불가능하면 가능한 요소로 F(x)
	분기3 ㅡ 점화식 모든 요소가 가능하다면 점화식 그대로 F(x)
*/

