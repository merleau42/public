using namespace std;
#include <bits/stdc++.h>

int cnt[100001];

int main(){
    int v, e, r;
    cin >> v >> e >> r; // vertex, edge, R
    
    vector<set<int>> edge(v+1);
    for (int i=0; i<e; i++) {
        int a,b;
        cin>>a>>b;
        edge[a].insert(b);
        edge[b].insert(a);
    }

    stack<int> st;
    
    st.push(r);
    int j=1;
    while( !st.empty() ){
        int current = st.top();
        st.pop();

        if ( cnt[current] != 0)
            continue;

        cnt[current] = j++;

        for ( auto i=edge[current].rbegin(); i!=edge[current].rend(); i++) {
            st.push( *i );
        }
    }

    for (int i=1; i<=v; i++) {
        cout << cnt[i] << '\n';
    }

    return 0;
}



/*
dfs(V, E, R) {   V : 정점 집합, E : 간선 집합, R : 시작 정점
    visited[R] <- YES;   시작 정점 R을 방문 했다고 표시한다.
    for each x ∈ E(R)   E(R) : 정점 R의 인접 정점 집합.(정점 번호를 오름차순으로 방문한다)
        if (visited[x] = NO) then dfs(V, E, x);
}
*/