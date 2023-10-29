using namespace std;
#include <bits/stdc++.h>
//https://www.acmicpc.net/problem/5567

int main(){
	int v, e;
	cin >> v >> e;
	int Start=1;
	vector<vector<int>> Graph(v+1);

	// 그래프 매핑하기
	for (int i=1; i<=e; i++) {
		int v1, v2;
		cin >> v1 >> v2;
		Graph[v1].push_back(v2);
		Graph[v2].push_back(v1);
	}
	
	set<int> frnd;

	for(int i: Graph[1])
		frnd.insert(i);
	
	for(int i: Graph[1])
		for(int j: Graph[i])
			frnd.insert(j);

	if (!frnd.empty())
		cout << frnd.size()-1;
	else
		cout << 0;
	
	return 0;
}