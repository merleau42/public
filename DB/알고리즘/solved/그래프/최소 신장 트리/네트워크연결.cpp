using namespace std;
#include <bits/stdc++.h>

struct adjacent{
    int start;
    int arrive;
    int cost;

    bool operator< (const adjacent &adj) const{
        return {this->cost > adj.cost};
    }
};

int parent[1001];

// 주어진 노드의 조상 노드를 찾는다 (노드가 소속된 서브 트리의 대표 노드)
int getParent(int node){
    if (parent[node] == node)
        return node;
    else
        return parent[node] = getParent(parent[node]);
}

// 두 노드가 공통의 조상을 갖도록한다 (노드 하나가 다른 트리에 흡수됨)
bool unionEdge(int nd1, int nd2){
    if ( getParent(nd1) < getParent(nd2) )
        parent[nd2] = getParent(nd1);
        return true;

    if ( getParent(nd1) > getParent(nd2) ) 
        parent[nd1] = getParent(nd2);
        return true;

    if ( getParent(nd1) == getParent(nd2) )
        return false;
}

int main(){
    int weight=0;
    int vertex, edge;
    cin >> vertex >> edge;

    priority_queue<adjacent> reserve;

    for (int i=1; i<=vertex; i++) {
        parent[i]=i;
    }

    for (int i=0; i<edge; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        reserve.push({a,b,c});
    }

    while( !reserve.empty() ){
        adjacent current = reserve.top();
        reserve.pop();

        int nd1 = current.start;
        int nd2 = current.arrive;

        if ( getParent(nd1) < getParent(nd2) ){
            parent[parent[nd2]] = parent[nd1];      
            weight += current.cost;

        }
        else if ( getParent(nd1) > getParent(nd2) ) {
            parent[parent[nd1]] = parent[nd2];
            weight += current.cost;
        }


        if ( getParent(nd1) < getParent(nd2) ){
            parent[nd2] = getParent(nd1);
            weight += current.cost;
        }
        else if ( getParent(nd1) > getParent(nd2) ) {
            parent[nd1] = getParent(nd2);
            weight += current.cost;
        }

    }

    cout << weight;

    return 0;
}