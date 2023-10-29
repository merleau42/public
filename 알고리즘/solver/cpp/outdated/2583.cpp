#include <bits/stdc++.h>
using namespace std;

bool visited[100][100];

struct point{
    int y,x;
    point operator+(const point &a) const{
        point r = {this->y + a.y, this->x + a.x};
        return r;
    }
    bool fit(int r,int c){
        return this->x >= 0 & this->x < c & this->y >= 0 & this->y < r;
    }
};
point dir[4] = {{0,1},{0,-1},{1,0},{-1,0}};

struct Sq{
    int lbx;
    int lby;
    int rtx;
    int rty;
};
bool contain(point cur,vector<Sq> &v){
    for(auto s : v){
        if( cur.x >=s.lbx && cur.x <= s.rtx && cur.y >= s.lby && cur.y <=s.rty){
            return true;
        }
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int m,n,k;
    cin>>m>>n>>k;
    vector<Sq> v;
    for(int i=0;i<k;i++){
        int lbx,lby,rtx,rty;
        cin>>lbx>>lby>>rtx>>rty;
        v.push_back({lbx,lby,rtx-1,rty-1});
    }
    queue<point> q;
    vector<int> ans;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(visited[i][j] ||contain({i,j},v))
                continue;
            int s = 0;
            visited[i][j] = true;
            q.push({i,j});
            while(!q.empty()){
                point cur = q.front();
                q.pop();
                s++;
                for(point d : dir){
                    point t = cur + d;
                    if(t.fit(m,n) && !visited[t.y][t.x]){
                        visited[t.y][t.x] = true;
                        if(!contain(t,v))
                            q.push(t);
                    }
                }
            }
            ans.push_back(s);
        }
    }
    sort(ans.begin(),ans.end());
    cout<<ans.size()<<'\n';
    for(auto i : ans)
        cout<<i<<' ';
} 