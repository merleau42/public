using namespace std;
#include <bits/stdc++.h>
int n, r;
vector<int> seq;
set<vector<int>> nPr(int);
set<set<int>> nCr(int);
template <typename T1> void draw(T1,string);

int main(){
	seq.push_back(0);
	string s;
	cin >> s;

	for (char e: s) {
		seq.push_back(e);
	}

	draw( nPr(4), "char" );

	return 0;
}

set<set<int>> nCr(int r) {
	set<set<int>> sector;
	sort(seq.begin()+1, seq.end());

	do{
		set<int> tmp;
		for(int i=1; i<=r; i++)
			tmp.insert(seq[i]);
		sector.insert(tmp);
	} while ( next_permutation(seq.begin()+1, seq.end()) );

	return sector;
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

template <typename T1>
void draw(T1 container, string option){
	for (auto i: container){
		if (option=="int")
			for (int j : i)
				cout << j << ' ';

		if (option=="char")
			for (char j : i)
				cout << j << ' ';

		cout << '\n';
	}
}