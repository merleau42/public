using namespace std;
#include <bits/stdc++.h>
#define INF 987654321
#define CAP -1
#define ROW 1
#define COL 1
int r=1, c=1;	// 행렬의 규모
int Y1,Y2,X1,X2;
int n;		// 수열의 크기 (모든 항의 갯수)
int m;
int Q;		// 쿼리의 갯수
int T;		// 테스트 케이스의 갯수
int A,B;	// A항에서 B항까지
int k=2;	// A항부터 연속된 K개의 항

int seq[CAP];		// 수열의 원본
long psum[CAP];	 		// 누적합 ㅡ 1항부터 n항까지의 합

int grid[CAP][CAP];	// 행렬의 원본
long gsum[CAP][CAP];	// 누적합 ㅡ (1,1)항 부터 (r,c)항 까지의 합

long rsum(int,int); // 구간합 (A항부터 B항까지의 합)
long csum(int,int); // 연속합 (A항부터 연속된 k개 항의 합)
void draw();

int main(){
	cin >> n;

	// 요건이 되는 값
	cin >> m;

	// 수열을 입력 받으면서, 누적합(psum) 작성
	psum[0] = 0;
	for (int i=1; i<=n; i++){
		cin >> seq[i];
		psum[i] = psum[i-1] + seq[i];
	}

	// 입력이 다닥다닥 붙어서 주어지는 경우
	psum[0] = 0;
	for (int i=1; i<=n; i++){
		cin >> seq[i];
		seq[i] = seq[i] - '0';
		psum[i] = psum[i-1] + seq[i];
	}

	// 자연수 배열 작성
	for (int i=1; i<=n; i++) {
		seq[i] = i;
	}

	// 행렬이 주어지는 경우, 입력과 동시에 누적합(gsum) 작성
	cin >> r >> c;
	for (int i=1; i<=r; i++) {
		for (int j=1; j<=c; j++) {
			cin >> grid[i][j];
			gsum[i][j]
			= gsum[i][j-1] + gsum[i-1][j]
			+ grid[i][j] - gsum[i-1][j-1];
		}
	}

	// 수열의 각 항에 대한 전처리
	for (int i=1; i<=n; i++) {
		//seq[i];
	}

	// 너비 K++의 슬라이드가 이동하면서 각 구간을 스캔
	int sum=0;
	for (int k=1; k<=n; k++) {	
		for (int i=1; i<=n-k+1; i++){
			//csum(i,k)
			cout << csum(i,k) << '\t';
		}
		cout << '\n';
	}


	cin >> Q;	// 질의는 Q번 주어짐
	for (int i=0; i<Q; i++) {
		cin >> A >> B;
	}


	cin >> T;	// 테스트 케이스
	cin >> k;	// 슬라이드의 너비 등, modifier

	draw();

	return 0;
}

// 구간합(A이상 B이하)
long rsum(int A, int B)  { return psum[B] - psum[A-1]; }

// 연속합(A포함 K개) ㅡ K 슬라이드
long csum(int A, int K)  { return psum[A+K-1] - psum[A-1]; }

// 행렬의 구간합 ㅡ 상좌(r1,c1) ~> 하우(r2,c2)
long rsum_grid(int r1, int c1, int r2, int c2){
	return gsum[r2][c2]
		 - gsum[r2][c1-1] - gsum[r1-1][c2]
		 + gsum[r1-1][c1-1];
}

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

	cout << "\n" << "행렬의 누적합" << "\n";
	for (int i=1; i<=r; i++) {
		for (int j=1; j<=c; j++) {
			cout << grid[i][j]
				 << "(" << gsum[i][j] << ")\t";
		}
		cout << "\n";
	}

	cout << "\nㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n";
}