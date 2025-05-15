using namespace std;
#include <bits/stdc++.h>
#define ROW 1
#define COL 100001

int r, c;			// 행렬 규모
int vist[ROW][COL];		// 좌표의 방문 여부나, 재방문 횟수-1

int dist[ROW][COL];		// 좌표까지 최단 거리 (이동 횟수, 노드의 level)
int depth;				// 가장 멀리 도달한 거리 (이동 횟수)

void init(){
	fill(&vist[0][0], &vist[0][0] + ROW*COL, 0);
	fill(&dist[0][0], &dist[0][0] + ROW*COL, -1);
}

struct Point {		// 좌표
	int y, x;
};

Point Start;	// 시작점
Point Final;	// 목적지

// 탐색 예약 배제 ㅡ 비정상적인 좌표
bool insane(Point next){
	return	 !(0 <= next.y && next.y < r
			&& 0 <= next.x && next.x < c);
}

void BFS(queue<Point> &reserve);

void draw(int arr[ROW][COL], int beg=0) {
	cout << "\n\n\n";
	for (int i=beg; i<r+beg; i++) {
		for (int j=beg; j<c+beg; j++) {
			cout << arr[i][j] << '\t';
		}
		cout << '\n';
	}
}

int previous;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

	r=1;
	c=100001;

	// 시작점과 목적지를 입력
	cin >> Start.x;
	cin >> Final.x;

	// 배열 초기화
	init();

	// 방문할 좌표가 예약되는 스케쥴
	queue<Point> reserve;

	// 시작점의 좌표 하나를 방문 예약, 시작점의 정보를 초기화 
	reserve.push( Start );
	dist[Start.y][Start.x]=0;
	vist[Start.y][Start.x]=0;
	BFS( reserve );
	
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

		// 목적지에 방문하였다면?
		if (current.x == Final.x && current.y == Final.y) {
			cout << dist[current.y][current.x];
			return;
		}

		// 인접 좌표를 생성 ㅡ for문을 깨서 직접 설정도 가능
		vector<Point> preview;
		preview.push_back( {0, current.x * 2} );
		preview.push_back( {0, current.x + 1} );
		preview.push_back( {0, current.x - 1} );

		// 다음 레벨 탐색 ㅡ 현재 위치와 인접하는 좌표를 방문 예약
		for ( Point next : preview) {
			// 인접 좌표의 스케쥴 편입 여부를 검사 (예시)
			// ㅡ 인접 좌표가 비정상적인 좌표라면 탈락
			// ㅡ 인접 좌표의 최단 거리가 이미 평가되었다면 탈락
			// ㅡ 인접 좌표가 장애물/용암/벽 등 통제 구역이라면 탈락
			if ( insane(next) )  continue;
			if ( dist[next.y][next.x] != -1 )  continue;
			
			// 인접 좌표가 모든 검열을 통과함
			// 인접 좌표에 (=다음 레벨 모든 좌표에) 적용시킬 내용
			dist[next.y][next.x] = dist[current.y][current.x] + 1;
			depth = dist[next.y][next.x];

			// 인접 좌표를 방문 예약
			reserve.push( next );
		}
	}
}