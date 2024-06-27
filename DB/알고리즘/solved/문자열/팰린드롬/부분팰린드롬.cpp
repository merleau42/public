using namespace std;
#include <bits/stdc++.h>
#define NUM 1000001
bool isPalind(int);
bool isPalind(string);

string s="Z";

int main(){
	ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
	int n;
	cin >> n;

	for (int i=0; i<n; i++) {
		string tmp;
		cin >> tmp;
		s += tmp;
	}

	cout << s << '\n';

	int T;
	cin >> T;
	while (T--){
		int S, E;
		cin >> S >> E;

		cout << isPalind( s.substr(S,E-S+1) ) << '\n';
	}

	
}

bool isPalind(int x){
	string s;
	s = to_string(x);
	reverse(s.begin(), s.end());

	return (s == to_string(x));
}

bool isPalind(string x){
	string s;
	s = x;
	reverse(s.begin(), s.end());

	return (s == x);
}