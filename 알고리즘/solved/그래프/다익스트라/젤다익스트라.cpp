using namespace std;
#include <bits/stdc++.h>

int dist[125][125];      // (0,0)부터의 비용
int INF = 125*125*9;
int mapping[125][125];
bool visited[125][125];

struct Point{
    int y, x, rupee;
    Point operator+(const Point &cur) const{
        return {this->y+cur.y, this->x+cur.x, 0} ;
    }
    bool operator<(const Point &cur) const{
        return this->rupee > cur.rupee;
    }    
};

Point dir[] = { {1,0,0}, {-1,0,0}, {0,1,0}, {0,-1,0} };

bool insane(Point pre, int n){
	return (!(0 <= pre.y && pre.y < n && 0 <= pre.x && pre.x < n));
}

int main(){
    int n;
    cin >> n;

    int testCase=1;
    while(n){
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                cin >> mapping[i][j];
                dist[i][j] = INF;
                visited[i][j] = false;
            }
        }
        dist[0][0]=mapping[0][0];

        priority_queue<Point> reserve;
        reserve.push( {0,0,mapping[0][0]} );

        while( !reserve.empty() ){
            Point current = reserve.top();
            reserve.pop();

            if (visited[current.y][current.x])
                continue;
            visited[current.y][current.x] = true;
            
            for (Point d: dir){
                Point next = current + d;

                if (insane(next, n))
                    continue;
                
                // 기존 비용이 새 비용보다 비싸다면 새 비용으로 갱신해 줌
                if (dist[next.y][next.x] > dist[current.y][current.x] + mapping[next.y][next.x]){
                    dist[next.y][next.x] = dist[current.y][current.x] + mapping[next.y][next.x];
                    next.rupee = dist[next.y][next.x];
                    reserve.push ( next );
                }
            }
        }                
        cout << "Problem " << testCase++ << ": " << dist[n-1][n-1] << '\n';
        cin >> n;
    }
    return 0;
}