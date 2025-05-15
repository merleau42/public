using namespace std;
#include <bits/stdc++.h>
int n, r;
vector<int> seq;
set<vector<int>> nPr(int);

int main(){
	seq.push_back(0);
	string s;
	cin >> s;

	for (char e: s) {
		seq.push_back(e);
	}


	for ( vector<int> v: nPr(s.size()) ) {
		string s1(v.begin(), v.end());
		string s2(v.begin(), v.end());

		reverse(s2.begin(), s2.end());

		if (s1 == s2){
			cout << s1;
			return 0;
		}
	}

	cout << "I'm Sorry Hansoo";

	return 0;
}

set<vector<int>> nPr(int r) {
	set<vector<int>> sector;
	sort(seq.begin()+1, seq.end());

	do{
		vector<int> tmp;
		for(int i=1; i<=r; i++)
			tmp.push_back(seq[i]);
		sector.insert(tmp);
	} while ( next_permutation(seq.begin()+1, seq.end()) );

	return sector;
}