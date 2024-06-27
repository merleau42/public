using namespace std;
#include <bits/stdc++.h>
#define NUM 100050001
bool isPrime[NUM];
string s;

int main(){
	ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
	int A, B;
	cin >> A >> B;

	for (int i=2; i<=10000000; i++)
		isPrime[i]=true;

	for (int i=2; i<=10000000; i++)
		if ( isPrime[i]  ){
			for (int j=2; j<=10000000/i; j++)
				isPrime[i*j] = false;
			if (A <= i && i <= B){
				s = to_string(i);
				reverse(s.begin(), s.end());
				if (s == to_string(i)){
					cout << s << ' ';
				}		
			}
		}
	cout << -1;
	return 0;
}