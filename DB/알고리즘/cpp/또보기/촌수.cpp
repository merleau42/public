using namespace std;
#include <bits/stdc++.h>
#define VER 101

int v, e;

int depth;

int dist[VER];
int vist[VER];

void init(){
	fill(dist, dist + v+1, -1);
	fill(vist, vist + v+1, 0);
}

int main(){
	int Start;
	int Final;
	cin >> v >> Start >> Final >> e;
	init();
	vector<vector<int>> Graph(v+1);
	for (int i=1; i<=e; i++) {
		int v1, v2;
		cin >> v1 >> v2;
		Graph[v1].push_back(v2);
		Graph[v2].push_back(v1);
	}
	queue<int> reserve;
	reserve.push( Start );
	dist[Start]=0;
	while ( !reserve.empty() ){
		int current=reserve.front();
		reserve.pop();
		if ( vist[current]++ )
			continue;
		if (current == Final) {
			cout << dist[current];
			return 0;
		}
		for (int next: Graph[current]){
			if (dist[next] != -1)
				continue;
			dist[next] = dist[current] + 1;
			depth = dist[next];
			reserve.push( next );
		}
	}
	cout << -1;
	return 0;
}