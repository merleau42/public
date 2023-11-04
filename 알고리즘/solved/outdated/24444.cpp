using namespace std;
#include <bits/stdc++.h>

int visited[100001]; // 방문된 순서

int main(){
    int v, e, r;
    cin >> v >> e >> r;

    vector<set<int>> edge(v+1);

    for (int i=0; i<e; i++) {
        int a,b;
        cin >> a >> b;
        edge[a].insert(b);
        edge[b].insert(a);
    }

    queue<int> reserve;
    reserve.push(r);

    int j=1;

    while ( !reserve.empty() ){
        int current = reserve.front();
        reserve.pop();

        if (visited[current])
            continue;
        
        visited[current]=j++;

        for ( int i : edge[current] ){
            reserve.push( i );
        }
    }

    for (int i=1; i<=v; i++) {
        cout << visited[i] << '\n';
    }

    return 0;
}