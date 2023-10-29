using namespace std;
#include <bits/stdc++.h>

struct Point{
    int z; 
    int y; 
    int x;
    Point operator+(const Point &dot){
        return {this->z+dot.z, this->y+dot.y, this->x+dot.x} ;
    }
    bool fit(int h, int r, int c){
	    return x >=0 & x<c & y >=0 & y<r & z>=0 & z<h; //bool형이라 비트연산자, 추론으로 this생략
    }
};
int tomato[100][100][100];

Point dir[] = {{1,0,0}, {-1,0,0}, {0,1,0}, {0,-1,0}, {0,0,1}, {0,0,-1}};


int main(){
    int c, r, h;
    cin >> c >> r >> h;

    queue<Point> reserve;

    for (int i=0; i<h; i++) {
        for (int j=0; j<r; j++) {
            for (int k=0; k<c; i++) {
                cin >> tomato[i][j][k];
                if ( tomato[i][j][k]==1 )
                    reserve.push( {i,j,k} );
            }
        }
    }

    while (!reserve.empty()){
        Point current = reserve.front();
        reserve.pop();

        for (Point i: dir){
            Point pre = current+i;
            
            if ( !pre.fit(h,r,c) || tomato[pre.z][pre.y][pre.x])
                continue;

            tomato[pre.z][pre.y][pre.x] = tomato[current.z][current.y][current.x] + 1;
            reserve.push(pre);
        }
    }
    
    int mature=0;
    for (int i=0; i<h; i++) {
        for (int j=0; j<r; j++) {
            for (int k=0; k<c; i++) {
                if (tomato[i][j][k]==0){
                    cout << -1;
                    return 0;
                }
                mature = max(mature, tomato[i][j][k]);
            }
        }
    }

    cout << mature-1;
    return 0;
}