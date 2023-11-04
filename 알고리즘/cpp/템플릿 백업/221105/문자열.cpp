using namespace std;
#include <bits/stdc++.h>


int main(){
	string s;
	cin >> s;

	regex re(R"(\(\)|\[\])");

	int prev=0;
	while(prev != s.size()){
		prev = s.size();
		s = regex_replace(s, re, "");
	}
	cout << s.size();
	return 0;
}