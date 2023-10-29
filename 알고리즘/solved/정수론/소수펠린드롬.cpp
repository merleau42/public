using namespace std;
#include <bits/stdc++.h>
#define NUM 2000001
bool isPrime[NUM];
string s;

int main(){
	int n, m;
	cin >> n;

	for (int i=2; i<=NUM; i++)
		isPrime[i]=true;

	for (int i=2; i<=NUM; i++)
		if ( isPrime[i]  ){
			for (int j=2; j<=NUM/i; j++)
				isPrime[i*j] = false;
			if (n <= i){
				s = to_string(i);
				reverse(s.begin(), s.end());
				if (s == to_string(i)){
					cout << s;
					return 0;
				}		
			}
		}
	return 0;
}