using namespace std;
#include <bits/stdc++.h>
#define INF 987654321
#define ROW 5
#define COL 5
//https://www.acmicpc.net/problem/2583

int r, c, h;	// 행렬 규모
int grid[ROW][COL];	// 행렬의 상황을 매핑
vector<int> range; // 인접한 좌표의 묶음들

int meet;		// 새로 방문한 노드의 수
int depth;		// 가장 멀리 도달한 거리 (이동 횟수)
int weight;		// 가장 멀리 도달한 비용 (누적 가중치)

int Rank[ROW][COL];	// 좌표가 최초로 방문된 순서
int dist[ROW][COL];	// 좌표까지 최단 거리 (이동 횟수, 노드의 level)
int cost[ROW][COL];	// 좌표까지 최단 비용 (누적 가중치)
int vist[ROW][COL];	// 좌표의 방문 여부나, 재방문 횟수-1

void init(){
	fill(&Rank[0][0], &Rank[0][0] + ROW*COL, 0);
	fill(&dist[0][0], &dist[0][0] + ROW*COL, -1);
	fill(&cost[0][0], &cost[0][0] + ROW*COL, INF);
	fill(&vist[0][0], &vist[0][0] + ROW*COL, 0);
}

void draw(int arr[ROW][COL], int option=0) {
    cout << "\nㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n";
    for (int i=0; i<r; i++) {
        for (int j=0; j<c; j++) {
			if (option == 0)
				cout << arr[i][j] << '\t';
			if (option == 1){
				if ( arr[i][j]==0 ) cout << "□ ";
				if ( arr[i][j]==1 ) cout << "■ ";
			}
        }
		cout << '\n';
    }
	cout << '\n';
}

struct Point {		// 좌표
	int y, x, z;

	// 인접 좌표를 생성하는 덧셈 연산 (좌표+방향=인접)
    Point operator+(const Point &cursor) const{
        return {this->y+cursor.y, this->x+cursor.x} ;
    }
};

Point Start;	// 시작점
Point Final;	// 목적지

// 인접성의 기준 (탐색할 좌표를 생성하는 기준)
Point adjacent[] = { {1,0}, {-1,0}, {0,1}, {0,-1} };

// 탐색 예약 배제 ㅡ 비정상적인 좌표
bool insane(Point next){
	return (!(0 <= next.y && next.y < r && 0 < next.x && next.x < c));
}

void BFS(queue<Point> &reserve);
void DFS(stack<Point> &reserve);

int main() {
	r=5; c=5;
	init();
	stack<Point> reserve;

	// 지도를 매핑하기
	for (int i=0; i<r; i++){
		for (int j=0; j<c; j++){
			cin >> grid[i][j];
		}
	}
	Start={0, 0};
	// 1. 시작점의 좌표 하나를 방문 예약, 시작점의 정보를 초기화 
	reserve.push( Start );
	dist[Start.y][Start.x]=0;
	draw(dist);
	DFS( reserve );
	draw(dist);
/*
	// 2. 시작점의 모든 좌표를 동시에 방문 예약 (동시 확산)
	for (int i=0; i<r; i++) {
		for (int j=0; j<c; j++) {
			if ( grid[i][j] != "정상") continue;
			reserve.push( {i, j} );
			dist[i][j]=0;
			vist[i][j]=0;
		}
	}
	DFS( reserve );

	// 3. 존재하는 모든 좌표를 시작점으로 출발 (각개의 확산 영역)
	for (int i=0; i<r; i++){
		for (int j=0; j<c; j++) {
			if ( grid[i][j] != "정상") continue;
			if ( vist[i][j] ) continue;
			reserve.push( {i, j} );
			dist[i][j]=0;
			vist[i][j]=0;
			meet=0;
			depth=0;
			DFS( reserve );
			range.push_back ( meet );
		}
	}*/
	
	return 0;
}
void DFS(stack<Point> &reserve){
	// 시작점으로 부터 방문 시작 ㅡ 예약이 없어질때까지 방문
	string s="";
	while ( !reserve.empty() ) {
		// 좌표를 방문하여 현재 위치를 갱신
		// 방문한 좌표를 스케쥴에서 제거하기
		Point current = reserve.top();
		reserve.pop();

		// 다음 레벨 탐색 ㅡ 현재 위치와 인접하는 좌표를 방문 예약
		for ( Point dir : adjacent) {
			// 인접 좌표를 하나 생성
			Point next = current + dir;

			// 인접 좌표의 스케쥴 편입 여부를 검사
			// ㅡ 인접 좌표가 비정상적인 좌표라면 탈락
			// ㅡ 인접 좌표의 최단 거리가 이미 평가되었다면 탈락
			// ㅡ 인접 좌표가 통제 구역에 포함된다면 탈락
			if (insane(next))
				continue;
			// 인접 좌표가 모든 검열을 통과함
			// 인접 좌표에 (=다음 레벨 모든 좌표에) 적용시킬 내용
			dist[next.x][next.y] = dist[current.x][current.y] + 1;
			depth = dist[next.x][next.y];

			// 인접 좌표를 방문 예약
			reserve.push( next );
		}
	}
}