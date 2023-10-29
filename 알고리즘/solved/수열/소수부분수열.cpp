using namespace std;
#include <bits/stdc++.h>
bool isPrime[10000022];


int n;	// 수열의 크기 (모든 항의 갯수)
int T;	// 테스트 케이스의 갯수

int seq[10022];		// 수열의 원본
long psum[10022];	 // 누적합 (1항부터 n항까지의 합)

// 연속합 (A항부터 연속된 k개 항의 합)
long csum(int A, int K)  { return psum[A+K-1] - psum[A-1]; }

int main(){
	cin >> T;
	// 2부터 10022까지 아직 판정되지 않음
	for (int i=2; i<=10022; i++)
		isPrime[i]=true;

	// 1부터 10022까지 소수 판별 함수 구축
	for (int i=2; i<=10022; i++)
		if ( isPrime[i]  )
			for (int j=2; j<=10022/i; j++)
				isPrime[i*j] = false;

	while (T--){
		fill(seq, seq+10022, 0);
		fill(psum, psum+10022, 0);

		cin >> n;
		// 수열을 입력 받음
		for (int i=1; i<=n; i++)
			cin >> seq[i];

		// 누적합 작성
		psum[0] = 0;
		for (int i=1; i<=n; i++)
			psum[i] = psum[i-1] + seq[i];
		
		bool flag=true;
		for (int k=2; k<=n && flag; k++) {
			for (int i=1; i<=n-k+1 && flag; i++){
				if( isPrime[csum(i,k)] ){
					flag=false;
					cout << "Shortest primed subsequence is length ";
					cout << k << ": ";
					for (int j=0; j<=k-1; j++)
						cout << seq[i+j] << ' ';
					cout << '\n';
					break;
				}
			}
		}
		if (flag) cout << "This sequence is anti-primed.\n";
	}

	return 0;
}
