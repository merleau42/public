#include <bits/stdc++.h>
using namespace std;
// https://www.acmicpc.net/problem/1931


// 전역 변수: 변수나 배열의 값이 자동으로 0으로 초기화
struct meeting{
	int start, end;

	bool operator< (const meeting &given) const{
		if (this->end == given.end){
			return this->start < given.start;
		}

		return this->end < given.end;
	}
};

meeting M[100000];

int main(){
	//입력 받기
	int n;
	cin >> n;

	for (int i=0; i<n; i++) {
		cin >> M[i].start;
		cin >> M[i].end;
	}

	sort(M, M+n);

	int res=0;
	int current=0;

	for (int i=0; i<n; i++) {
		if (M[i].start >= current){
			current = M[i].end;
			res += 1;
		}
	}

	cout << res;

	return 0;
}