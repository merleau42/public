using namespace std;
#include <bits/stdc++.h>
//https://www.acmicpc.net/problem/75969
int r, c, h;	// 행렬 규모
int grid[100][100][100];	// 행렬의 상황을 매핑
struct Point {		// 좌표
	int z, y, x;
    Point operator+(const Point &cursor) const{
        return {this->z+cursor.z, this->y+cursor.y, this->x+cursor.x} ;
    }
};

bool OutOfBound(Point next){
	return	 !(0 <= next.z && next.z < h
			&& 0 <= next.y && next.y < r
			&& 0 <= next.x && next.x < c);
}

int main() {
	cin >> c >> r >> h;
	Point adjacent[] = { {1,0,0}, {-1,0,0}, {0,1,0}, {0,-1,0}, {0,0,1}, {0,0,-1}};
	queue<Point> reserve;
	for (int i=0; i<h; i++)
		for (int j=0; j<r; j++)
			for (int k=0; k<c; k++) {
				cin >> grid[i][j][k];
				if (grid[i][j][k]==1)
					reserve.push( {i, j, k} );
			}

	while ( !reserve.empty() ) {
		Point current = reserve.front();
		reserve.pop();

		for ( Point dir : adjacent) {
			Point next = current + dir;

			if (!OutOfBound(next) && grid[next.z][next.y][next.x] == 0){
				grid[next.z][next.y][next.x] = grid[current.z][current.y][current.x] + 1;
				reserve.push( next );
			}
		}
	}

	int mn = 0;
	for (int i=0; i<h; i++)
		for (int j=0; j<r; j++)
			for (int k=0; k<c; k++) {
				if (grid[i][j][k]==0){
					cout << -1;
					return 0;
				}
				mn = max(mn, grid[i][j][k]);	
			}

	cout << mn - 1;
	return 0;
}