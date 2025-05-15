#include <bits/stdc++.h>
using namespace std;

int tomato[100][100][100];
struct Point{
    int z,y,x;
    Point operator+(const Point &a) const {
        return {z + a.z,y + a.y,x + a.x};
    }
    bool fit(int h,int r,int c){
        return x >= 0 & x < c & y >= 0 & y < r & z >= 0 & z < h;
    }
};
Point dir[6] = {{1,0,0},{-1,0,0},{0,1,0},{0,-1,0},{0,0,1},{0,0,-1}};
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int c,r,h;
    cin>>c>>r>>h;
    queue<Point> q;
    for(int i = 0; i < h; i++){
        for(int j = 0;j < r;j++){
            for(int k = 0;k < c;k++){
                cin >> tomato[i][j][k];
                if(tomato[i][j][k]==1){
                    q.push({i,j,k});
                }
            }
        }
    }

    while(!q.empty()){
        Point t = q.front();
        q.pop();
        int cur = tomato[t.z][t.y][t.x];
        for(auto d : dir){
            Point np = t + d;
            if(np.fit(h,r,c) && tomato[np.z][np.y][np.x] == 0){
                tomato[np.z][np.y][np.x] = cur + 1;
                q.push(np);
            }
        }
    }
    int m = 0;
    for(int i = 0; i < h; i++){
        for(int j = 0;j < r;j++){
            for(int k = 0;k < c;k++){
                if(tomato[i][j][k]==0){
                    cout <<-1;
                    return 0;
                }
                m = max(m,tomato[i][j][k]-1);
            }
        }
    }
    cout<<m;
    return 0;
}