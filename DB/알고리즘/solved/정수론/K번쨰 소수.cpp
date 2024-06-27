using namespace std;
#include <bits/stdc++.h>
#define NUM 10000000
bool isPrime[NUM];

vector<int> prime;	//x번쨰 소수 prime[x]

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
	int n;
	cin >> n;

	// 2부터 NUM까지 아직 판정되지 않음
	for (int i=2; i<=NUM; i++)
		isPrime[i]=true;

	// 1부터 NUM까지 소수 판별 함수 구축
	prime.push_back(0);
	for (int i=2; i<=NUM; i++)
		if ( isPrime[i]  ){
			prime.push_back( i );
			for (int j=2; j<=NUM/i; j++)
				isPrime[i*j] = false;
		}
	
	cout << prime[n];

	return 0;
}