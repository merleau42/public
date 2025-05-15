using namespace std;
#include <bits/stdc++.h>
//https://www.acmicpc.net/problem/9375

int main(){
	int T;
	cin >> T;
	while (T--){
		int n;
		cin >> n;
		map<string,int> cloth;
		while(n--){
			string s;
			cin >> s;
			cin >> s;

			cloth[s]++;
		}

		int gop=1;
		for (auto e: cloth)
			gop *= (e.second + 1);
		
		cout << gop-1 << '\n';
	}
	return 0;
}