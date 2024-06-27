using namespace std;
#include <bits/stdc++.h>

bool visited[100][100];

struct Point{
    int y,x;
    Point operator+(const Point &cur) const{
        return {this->y+cur.y, this->x+cur.x} ;
    }
    bool allowed(int r, int c){
        return 0<=this->y && this->y<r && 0<=this->x && this->x<c;
    }
};
Point dir[] = { {1,0}, {-1,0}, {0,1}, {0,-1} };

struct square{
    int bx;
    int by;
    int tx;
    int ty;
};
bool fit(Point cur, vector<square> &rect){
    for (auto s : rect) {
        if(s.by <= cur.y  &&  cur.y < s.ty  &&  s.bx <= cur.x && cur.x < s.tx){
            return true;
        }
    }
    return false;
}

int main(){
    int r, c, k;
    cin >> r >> c >> k;
    vector<square> rect;
    for (int i=0; i<k; i++) {
        int bx, by, tx, ty;
        cin >> bx >> by >> tx >> ty;
        rect.push_back({bx, by, tx, ty});
    }
    queue<Point> reserve;
    vector<int> scope;
    for (int i=0; i<r; i++) {
        for (int j=0; j<c; j++) {
            if ( visited[i][j] || fit ({i, j}, rect) ) 
                continue;
            int meet=0;
            visited[i][j] = true;
            reserve.push( {i, j} );
            while ( !reserve.empty()) {
                Point current = reserve.front();
                reserve.pop();
                meet++;
                for ( Point d : dir ) {
                    Point pre = current+d; 
                    if ( pre.allowed(r,c) && !visited[pre.y][pre.x] ){
                        visited[pre.y][pre.x] = true;
                        if(!fit(pre,rect))
                           reserve.push( pre );
                    }
                }
            }
            scope.push_back(meet);
        }
    }
    //set을 사용해서 자동 정렬을 했더니 중복제거가 되어버린듯
    sort(scope.begin(), scope.end());
    cout << scope.size() << '\n';
    for (int i: scope)
        cout << i << ' ';

    return 0;
}