using namespace std;
#include <bits/stdc++.h>
#define NUM 1000001
bool isPalind(int);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
	int n;
	cin >> n;

	for (int i=n+1; i<=NUM; i++) {
		if ( isPalind(i) ){
			cout << i;
			break;
		}
	}

	
}


bool isPalind(int x){
	string s;
	s = to_string(x);
	reverse(s.begin(), s.end());

	return (s == to_string(x));
}