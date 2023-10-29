using namespace std;
#include <bits/stdc++.h>
#define INF 987654321
#define CAP 500001
int n;	  // 수열의 크기 (모든 항의 갯수)
int Q;	  // 쿼리의 갯수
int T;	  // 테스트 케이스의 갯수
int A,B;	// A항에서 B항까지
int k=2;	// A항부터 연속된 K개의 항

int seq[CAP];		// 수열의 원본

long psum[CAP];	 // 누적합 (1항부터 n항까지의 합)


int main(){
	cin >> n;

	// 다닥다닥 붙어서 주어지는 경우
	int sum=0;
	for (int i=1; i<=n; i++){
		char tmp;
		cin >> tmp;
		sum+=tmp-'0';
	}

	cout << sum;

	return 0;
}