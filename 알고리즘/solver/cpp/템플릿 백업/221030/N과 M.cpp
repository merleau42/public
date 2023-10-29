using namespace std;
#include <bits/stdc++.h>
int n, r;
vector<int> seq; 
void nPr();
void nCr();

int main(){
	cin >> n >> r;
	seq.push_back(0);

	for (int i=1; i<=n; i++){
		int e;
		cin >> e;
		seq.push_back(e);
	}

	nCr();

	return 0;
}

void nCr() {
	set<set<int>> sector;
	sort(seq.begin()+1, seq.end());

    do{
		set<int> tmp;
        for(int i=1; i<=r; i++)
			tmp.insert(seq[i]);
		sector.insert(tmp);
    } while ( next_permutation(seq.begin()+1, seq.end()) );

	for (set<int> i: sector){
		for (int j : i)
			cout << j << ' ';
		cout << '\n';
	}
}

void nPr() {
	set<vector<int>> sector;
	sort(seq.begin()+1, seq.end());


    do{
		vector<int> tmp;
        for(int i=1; i<=r; i++)
			tmp.push_back(seq[i]);
		sector.insert(tmp);
    } while ( next_permutation(seq.begin()+1, seq.end()) );

	for (vector<int> i: sector){
		for (int j : i)
			cout << j << ' ';
		cout << '\n';
	}
}