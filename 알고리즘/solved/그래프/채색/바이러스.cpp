using namespace std;
#include <bits/stdc++.h>

int v, e;		// 노드의 수, 간선의 수
int meet;		// 처음 방문한 노드의 수
bool visited[101];

queue<int> reserve;	// 방문할 노드가 예약되는 스케쥴

int main(){
	// 노드와 간선의 수를 입력
    cin >> v >> e;
	vector<vector<int>> adjacent(v+1);	// 노드x에 인접하는 노드들

    for (int i=0; i<e; i++) {	// 노드들 사이의 간선 관계를 구축
        int a, b;
        cin >> a >> b;

        adjacent[a].push_back(b);
        adjacent[b].push_back(a);
    }

    reserve.push(1);	// 시작 노드를 방문 예약

    // 방문 === 예약이 없어질때까지
    while ( !reserve.empty() ){
        // 노드를 방문하면서 현재 위치를 갱신
        int current=reserve.front();

		// 노드를 스케쥴에서 제거하기
        reserve.pop();

		// 이미 방문했다면 즉시 떠나고, 처음이면 방문 기록
		if ( visited[current] ) continue;
		visited[current]=true;

		// 최초의 방문해서 할 일
		meet++;

        // 탐색 ㅡ 현재 위치와 인접하는 정점을 방문 예약
        for (int i: adjacent[current])
            reserve.push( i );
    }
    cout << meet-1;
    return 0;
}