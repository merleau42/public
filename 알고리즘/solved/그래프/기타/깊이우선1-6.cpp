using namespace std;
#include <bits/stdc++.h>
#define INF 987654321
//https://www.acmicpc.net/problem/24480

int v, e;		// 노드의 수, 간선의 수

int meet;
int depth;

int Rank[100001];
int dist[100001];

void init(){
	fill(Rank, Rank + v+1, 0);
	fill(dist, dist + v+1, -1);
}

int main(){
	int Start;
	cin >> v >> e >> Start;

	init();
	vector<vector<int>> Graph(v+1);// G(Nd)☞Nd에 인접하는 노드들

	for (int i=1; i<=e; i++) {
		int v1, v2;
		cin >> v1 >> v2;
		Graph[v1].push_back(v2);
		Graph[v2].push_back(v1);
	}

	stack<int> reserve;
	reserve.push( Start ); 
	dist[Start]=0;
	Rank[Start]=0;

	while ( !reserve.empty() ){
		int current = reserve.top();
		reserve.pop();

		if(Rank[current]!=0)
			continue;

		meet++;
		Rank[current]=meet;

		// 스택은 정렬시 주의, 거꾸로 되었음
		sort( Graph[current].begin(), Graph[current].end() );

		for(int next : Graph[current]){
			if (Rank[next] != 0)
				continue;

			dist[next] = dist[current] + 1;
			depth = dist[next];

			reserve.push( next );
		}
	}

	long long sum=0;
	for (int i=1; i<=v; i++)
		sum += (long long) dist[i]*Rank[i];
	
	cout << sum;

	return 0;
}

// void viewData(){
// 	cout << "\n";
// 	for (int i=1; i<=v; i++){
// 		cout << "\n";
// 		cout << i;
// 		cout << "\t순위" << Rank[i] << " ";
// 		cout << "\t거리" << dist[i] << " ";
// 		cout << "\t연결" << "ㅡ";
// 		for(int next : Graph[i]) cout << next << ' ';
// 	}
// }