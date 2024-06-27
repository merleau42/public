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
long rsum(int,int); // 구간합 (A항부터 B항까지의 합)
long csum(int,int); // 연속합 (A항부터 연속된 k개 항의 합)
void draw();

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr); 
    cin >> n;

    // 수열을 입력 받음
    for (int i=1; i<=n; i++)
        cin >> seq[i];

    // 누적합 작성
    psum[0] = 0;
    for (int i=1; i<=n; i++)
        psum[i] = psum[i-1] + seq[i];


    long mx = -INF;
    for (int k=1; k<=n; k++) {
        for (int i=1; i<=n-k+1; i++) {
            mx = max(mx, csum(i,k));
        }
    }
    cout << mx;

    return 0;
}

// 구간합(A이상 B이하)
long rsum(int A, int B)  { return psum[B] - psum[A-1]; }

// 연속합(A포함 K개) ㅡ K 슬라이드
long csum(int A, int K)  { return psum[A+K-1] - psum[A-1]; }


void draw(){
	cout << "\n수열\t";
	for (int i=1; i<=n; i++)
		cout << seq[i] << '\t';
	
	cout << "\n누적합\t";
	for (int i=1; i<=n; i++)
		cout << psum[i] << '\t';

	cout << "\n" << k << "연속합" << "\t";
	for (int i=1; i<=n-k+1; i++)
		cout << csum(i,k) << '\t';

	cout << "\nㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n";
}