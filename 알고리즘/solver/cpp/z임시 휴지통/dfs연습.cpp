using namespace std;
#include <bits/stdc++.h>
#define INF 987654321

int r;
int grid[25][25];
bool vist[25][25];

struct Point {
	int y, x;
    Point operator+(const Point &cursor) const{
        return {this->y+cursor.y, this->x+cursor.x} ;
    }
};
bool OutOfBound(Point next){
	return 0 > next.y || next.y >= r || 0 > next.x || next.x >= r;
}

int main() {
	cin >> r;
	Point adjacent[] = { {1,0}, {-1,0}, {0,1}, {0,-1} };
	stack<Point> reserve;
	vector<int> range;

	for (int i=0; i<r; i++)
		for (int j=0; j<r; j++){
			char tmp;
			cin >> tmp;
			grid[i][j] = tmp - '0';
		}


	for (int i=0; i<r; i++) {
		for (int j=0; j<r; j++) {
    	    if ( grid[i][j] && !vist[i][j] ){
                reserve.push( {i, j} );
				int meet=0;
				while ( !reserve.empty() ) {
					Point current = reserve.top();
					reserve.pop();

					if(vist[current.y][current.x])
						continue;
					vist[current.y][current.x]=true;
					meet++;

					for ( Point dir : adjacent) {
						Point next = current + dir;

						if (OutOfBound(next))
							continue;

						if (grid[next.y][next.x] != 1)
							continue;
							
						reserve.push( next );
					}
				}
				range.push_back(meet);
			}
		}
	}
	sort( range.begin(), range.end() );
	cout << range.size() << '\n';
	for (int i : range)
		cout << i << '\n';
	
	return 0;
}