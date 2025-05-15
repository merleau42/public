using namespace std;
#include <bits/stdc++.h>
#define INF 987654321
#define VER 100001
//https://www.acmicpc.net/problem/

int v, e;		// 노드의 수, 간선의 수
vector<vector<int>> Graph(VER);// G(Nd)☞Nd에 인접하는 노드들
vector<int> connected; // 인접한 노드의 묶음들 (연결 요소)

int meet;		// 새로 방문한 노드의 수
int depth;		// 가장 멀리 도달한 거리 (이동 횟수)
int weight;		// 가장 멀리 도달한 비용 (누적 가중치)

int Rank[VER];		// 노드가 최초로 방문된 순서
int dist[VER];		// 노드까지 최단 거리 (이동 횟수, 노드의 level)
int cost[VER];		// 노드까지 최단 비용 (누적 가중치)
int vist[VER];		// 노드의 방문 여부나, 재방문 횟수-1

void init(){
	fill(Rank, Rank + VER, 0);
	fill(dist, dist + VER, -1);
	fill(cost, cost + VER, INF);
	fill(vist, vist + VER, 0);
}

int Start;
int Final;

void draw(vector<vector<int>> &Graph);
void BFS(queue<int> &reserve);

int main(){
	// 노드와 간선의 수를 입력
	cin >> v;

	// 시작점과 목적지를 입력
	Start=1;

	// 배열 초기화
	init();

	// 방문할 노드가 예약되는 스케쥴
	queue<int> reserve;

	// 그래프 매핑하기
	for (int i=1; i<=v-1; i++) {
		int v1, v2;
		cin >> v1 >> v2;
		Graph[v1].push_back(v2);
		Graph[v2].push_back(v1);
	}

	// 1. 시작 노드를 방문 예약, 시작점의 정보를 초기화 
	reserve.push( Start );
	dist[Start]=0;
	Rank[Start]=0;
	vist[Start]=0;
	BFS( reserve );
	draw(Graph);

	for (int i=2; i<=v; i++) {
		for (int j : Graph[i]){
			if (dist[i] == dist[j]+1)
				cout << j << '\n';
		}
	}

	return 0;
}

void BFS(queue<int> &reserve){
	// 시작점으로 부터 방문 시작 ㅡ 예약이 없어질때까지 방문
	while ( !reserve.empty() ){
		// 노드를 방문하여 현재 위치를 갱신
		// 방문한 노드를 스케쥴에서 제거하기
		int current=reserve.front();
		reserve.pop();

		// 이미 방문했다면 즉시 떠나고, 처음이면 방문 기록
		if ( vist[current]++ )
			continue;
		
		// 최초의 방문에서 할 일
		meet++;

		// 동일 레벨 중에서도 해당 노드에만 적용될 작업
		Rank[current]=meet;

		// 목적지에 방문하였다면?
		if (current == Final) {
			// 뭔가를 하고 break;
		}
		// 인접 노드를 정렬하기
		// sort( Graph[current].begin(), Graph[current].end()> );

		// 다음 레벨 탐색 ㅡ 현재 위치와 인접하는 정점을 방문 예약
		for (int next: Graph[current]){
			// 인접 노드를 하나 들고있음 ㅡ next

			// 인접 노드의 스케쥴 편입 여부를 검사
			// ㅡ 인접 노드가 비정상적인 노드라면 탈락
			// ㅡ 인접 노드의 최단 거리가 이미 평가되었다면 탈락
			if (dist[next] != -1)
				continue;

			// 인접 노드가 모든 검열을 통과함, 방문 예약
			// 인접 노드에 (=다음 레벨 모든 노드에) 적용시킬 내용
			dist[next] = dist[current] + 1;
			depth = dist[next];

			// 인접 노드를 방문 예약
			reserve.push( next );
		}
	}
}
void draw(vector<vector<int>> &Graph) {
    cout << "\nㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n";
    for (int i=1; i<=v; i++) {
        cout << "노드 " << i << '\t';
        cout << "방문 " << vist[i] << '\t';
        cout << "순위 " << Rank[i] << '\t';
        cout << "거리 " << dist[i] << '\t';
		cout << "비용 " << cost[i] << '\t';
        cout << "인접 { ";
        for (int j: Graph[i]) cout << j << ", ";
        cout << "\b\b }\t\t";
        cout << "부모 ";
        for (int j: Graph[i]) if (dist[i] == dist[j]+1) cout << j << "-";
        cout << "\n";
    }
}