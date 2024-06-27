#include <bits/stdc++.h>
using namespace std;
#define ROW 200
#define COL 200

int r;		// 행렬 규모

int vist[ROW][COL];		// 좌표의 방문 여부나, 방문 횟수
int dist[ROW][COL];		// 좌표까지 최단 거리 (이동 횟수)

struct Point {			// 좌표 인스턴스
	int y, x;
	// 인접 좌표를 생성하는 덧셈 연산 (좌표+방향=인접)
    Point operator+(const Point &cursor) const{
        return {this->y+cursor.y, this->x+cursor.x} ;
    }
};

// 탐색 예약 배제 ㅡ 비정상적인 좌표
bool insane(Point next){
	return (!(0 <= next.y && next.y < r && 0 <= next.x && next.x < r));
}

int main() {
	cin >> r;
	Point Start;
	Point Final;
	cin >> Start.y >> Start.x;
	cin >> Final.y >> Final.x;

	Point adjacent[] = { {-2, -1}, {-2, +1}, {0, -2}, {0, +2}, {+2, -1}, {+2, +1} };
	
	queue<Point> reserve;
	reserve.push( Start );

	bool flag=true;
	while ( !reserve.empty() ) {
		Point current = reserve.front();
		reserve.pop();

		if ( vist[current.y][current.x]++ )
			continue;

		if (current.x == Final.x && current.y == Final.y) {
			cout << dist[current.y][current.x] << '\n';
			flag=false;
			break;
		}

		for ( Point dir : adjacent) {
			Point next = current + dir;

			if (insane(next))
				continue;
			if (dist[next.y][next.x] != 0)
				continue;
			
			dist[next.y][next.x] = dist[current.y][current.x] + 1;
			reserve.push( next );
		}
	}
	if(flag) cout << -1 << '\n';
	return 0;
}