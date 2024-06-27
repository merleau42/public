using namespace std;
#include <bits/stdc++.h>
#define INF 987654321
#define ROW 601
#define COL 601
//https://www.acmicpc.net/problem/

int r, c, h;	// 행렬 규모
int grid[ROW][COL];	// 행렬의 상황을 매핑

map<int,int> connected; // 연결 요소의 좌표의 갯수
int name;				// 탐색 중인 연결 요소의 이름
int band[ROW][COL]; 	// 좌표가 소속된 연결 요소

int meet;		// 새로 방문한 노드의 수
int depth;		// 가장 멀리 도달한 거리 (이동 횟수)
int weight;		// 가장 멀리 도달한 비용 (누적 가중치)
int gather;		// 수집한 재화

int vist[ROW][COL];		// 좌표의 방문 여부나, 재방문 횟수-1
int dist[ROW][COL];		// 좌표까지 최단 거리 (이동 횟수, 노드의 level)
int Rank[ROW][COL];		// 좌표가 최초로 방문된 순서
int value[ROW][COL];	// 좌표에 할당된 재화

// int cost[ROW][COL];	// 좌표까지 최단 비용 (누적 가중치)
// int toll[ROW][COL];	// 좌표에 할당된 가중치

void init(){
	connected.clear();
	fill(&vist[0][0], &vist[0][0] + ROW*COL, 0);
	fill(&dist[0][0], &dist[0][0] + ROW*COL, -1);
	fill(&Rank[0][0], &Rank[0][0] + ROW*COL, 0);
	//fill(&cost[0][0], &cost[0][0] + ROW*COL, INF);
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
vector<Point> preview;

// 통로와 장애물 기호
set<int> startable;
set<int> passable;
set<int> obstacle;

void draw(int arr[ROW][COL], int beg=0) {
	cout << "\nㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n";
	for (int i=beg; i<r+beg; i++) {
		for (int j=beg; j<c+beg; j++) {
			cout << arr[i][j] << '\t';
		}
		cout << '\n';
	}
	cout << '\n';
}

// 탐색 예약 배제 ㅡ 비정상적인 좌표
bool insane(Point next){
	return	 !(1 <= next.y && next.y <= r
			&& 1 <= next.x && next.x <= c);
}

void BFS(queue<Point> &reserve);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

	// 테스트 케이스의 갯수
	int T=1;

	while(T--){
		// 행렬의 규모를 입력
		cin >> r >> c;

		// 배열 초기화
		init();

		// 방문할 좌표가 예약되는 스케쥴
		queue<Point> reserve;

		// 지도를 매핑하기
		for (int i=1; i<=r; i++){
			for (int j=1; j<=c; j++){
				// 다닥다닥 붙어서 지도가 주어지는 경우
				char tmp;
				cin >> tmp;
				grid[i][j]=tmp;

				if (grid[i][j]=='P')
					value[i][j]=1;
			}
		}

		// 통로나 장애물, 재화의 기호와 성질을 정의
		startable = {'I'};
		passable = {'O', 'P', 'I'};
		obstacle = {'X'};

		// 3. 존재하는 모든 좌표를 시작점으로 개별 출발 (각개의 확산 영역)
		for (int i=1; i<=r; i++){
			for (int j=1; j<=c; j++) {
				if ( vist[i][j] ) continue;
				if ( startable.find( grid[i][j] )==startable.end() )
					continue;
				reserve.push( {i, j} );
				dist[i][j]=0;
				vist[i][j]=0;
				meet=0;
				depth=0;
				name++;
				BFS( reserve );
				connected[name] = meet;
			}
		}
		if (gather)	cout << gather;
		else cout << "TT";
	}
	
	return 0;
}

void BFS(queue<Point> &reserve){
	// 시작점으로 부터 방문 시작 ㅡ 예약이 없어질때까지 방문
	while ( !reserve.empty() ) {
		// 좌표를 방문하여 현재 위치를 갱신
		// 방문한 좌표를 스케쥴에서 제거하기
		Point current = reserve.front();
		reserve.pop();

		// 이미 방문했다면 즉시 떠나고, 처음이면 방문 기록
		if ( vist[current.y][current.x]++ )
			continue;

		// 최초의 방문에서 할 일
		meet++;

		// 동일 레벨 중에서도 해당 노드에만 적용될 작업
		Rank[current.y][current.x] = meet;
		band[current.y][current.x] = name;

		// 목적지에 방문하였다면?
		if (current.x == Final.x && current.y == Final.y) {
			// 뭔가를 하거나 break;
		}

		// 재화 수집
		gather += value[current.y][current.x];

		// 인접 좌표를 생성
		for ( Point dir : adjacent) {
			preview.push_back( current + dir );
		}

		// 다음 레벨 탐색 ㅡ 현재 위치와 인접하는 좌표를 방문 예약
		for ( Point next : preview) {
			// 인접 좌표의 스케쥴 편입 여부를 검사 (예시)
			// ㅡ 인접 좌표가 비정상적인 좌표라면 탈락
			// ㅡ 인접 좌표의 최단 거리가 이미 평가되었다면 탈락
			// ㅡ 인접 좌표가 장애물/용암/벽 등 통제 구역이라면 탈락
			if ( insane(next) )
				continue;
			if ( dist[next.y][next.x] != -1 )
				continue;
			if (passable.find(grid[next.y][next.x])==passable.end())
				continue;
			if (obstacle.find(grid[next.y][next.x])!=obstacle.end())
				continue;
			
			// 인접 좌표가 모든 검열을 통과함
			// 인접 좌표에 (=다음 레벨 모든 좌표에) 적용시킬 내용
			dist[next.y][next.x] = dist[current.y][current.x] + 1;
			depth = dist[next.y][next.x];

			// 인접 좌표를 방문 예약
			reserve.push( next );
		}
	}
}