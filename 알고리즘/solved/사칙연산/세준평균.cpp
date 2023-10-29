using namespace std;
#include <bits/stdc++.h>
#define INF 987654321

int main(){
	int n;
	cin >> n;

	// 수열을 입력 받음
	int sum=0;
	int mx = -INF;
	for (int i=1; i<=n; i++){
		int tmp;
		cin >> tmp;
		sum += tmp;
		mx = max(mx, tmp);
	}

	cout << (double)100*sum/(n*mx);

	return 0;
}
