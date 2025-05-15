#include <bits/stdc++.h>
using namespace std;//

int r;					// 행렬 규모
int visited[300][300];	// 좌표의 방문 여부나, 방문 횟수
int dist[300][300];		// 좌표까지 최단 거리 (시작 부터 이동 횟수)

struct Point {			// 좌표 인스턴스
	int x, y;
	// 인접 좌표를 생성하는 덧셈 연산 (좌표+방향=인접)
    Point operator+(const Point &cursor) const{
        return {this->x+cursor.x, this->y+cursor.y} ;
    }
};

void init(){
	for (int i=0; i<r; i++) {
		for (int j=0; j<r; j++) {
			visited[i][j]=0;
			dist[i][j]=0;
		}
	}
}

// 탐색 예약 배제 ㅡ 비정상적인 좌표
bool insane(Point next){
	return (!(0 <= next.y && next.y < r && 0 <= next.x && next.x < r));
}

int main() {
	// 테스크 케이스의 갯수
	int T;
	cin >> T;

	while(T--){
		cin >> r;
		Point Start;
		Point Final;
		cin >> Start.x >> Start.y;
		cin >> Final.x >> Final.y;
		init();

		Point adjacent[] = { {2,1}, {2,-1}, {-2,1}, {-2,-1}, {1,2}, {1,-2}, {-1,2}, {-1,-2} };
		
		queue<Point> reserve;	// 방문할 좌표가 예약되는 스케쥴
		reserve.push( Start );	
		
		while ( !reserve.empty() ) {
			Point current = reserve.front();
			reserve.pop();

			if ( visited[current.x][current.y]++ )
				continue;

			if (current.x == Final.x && current.y == Final.y) {
				cout << dist[current.x][current.y] << '\n';
				break;
			}

			for ( Point dir : adjacent) {
				Point next = current + dir;

				if (insane(next))
					continue;
				if (dist[next.x][next.y] != 0)
					continue;
				
				dist[next.x][next.y] = dist[current.x][current.y] + 1;
				reserve.push( next );
			}
		}

	}
	return 0;
}