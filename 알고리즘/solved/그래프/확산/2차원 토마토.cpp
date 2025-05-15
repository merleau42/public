using namespace std;
#include <bits/stdc++.h>
//https://www.acmicpc.net/problem/7576
int r, c, h;	// 행렬 규모
int grid[1000][1000];	// 행렬의 상황을 매핑
struct Point {		// 좌표
	int z, y, x;
    Point operator+(const Point &cursor) const{
        return {this->y+cursor.y, this->x+cursor.x} ;
    }
};

bool OutOfBound(Point next){
	return (!(0 <= next.y && next.y < r && 0 <= next.x && next.x < c));
}

int main() {
	cin >> c >> r;
	Point adjacent[] = { {1,0}, {-1,0}, {0,1}, {0,-1} };
	queue<Point> reserve;
	for (int i=0; i<r; i++)
		for (int j=0; j<c; j++) {
			cin >> grid[i][j];
			if (grid[i][j]==1)
				reserve.push( {i, j} );
		}

	while ( !reserve.empty() ) {
		Point current = reserve.front();
		reserve.pop();

		for ( Point dir : adjacent) {
			Point next = current + dir;

			if (!OutOfBound(next) && grid[next.y][next.x] == 0){
				grid[next.y][next.x] = grid[current.y][current.x] + 1;
				reserve.push( next );
			}
		}
	}

	int mn = 0;
	for (int i=0; i<r; i++) {
		for (int j=0; j<c; j++) {
			if (grid[i][j]==0){
				cout << -1;
				return 0;
			}
			mn = max(mn, grid[i][j]);
		}
	}
	cout << mn - 1;
	return 0;
}