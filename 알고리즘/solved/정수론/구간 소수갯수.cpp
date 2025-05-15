using namespace std;
#include <bits/stdc++.h>
#define NUM 10000001
bool isPrime[NUM];

int main(){
	// 2부터 NUM까지 아직 판정되지 않음
	for (int i=2; i<=NUM; i++)
		isPrime[i]=true;

	// 1부터 NUM까지 소수 판별 함수 구축
	for (int i=2; i<=NUM; i++)
		if ( isPrime[i]  )
			for (int j=2; j<=NUM/i; j++)
				isPrime[i*j] = false;

		int m, n;
		while (cin >> m >> n){
			// M이상 N이하 값 사이에 존재하는 소수 갯수
			int sum=0;
			for (int i=m; i<=n; i++)
				if ( isPrime[i] )
					sum++;

			cout << sum << "\n\n";
		}
	return 0;
}