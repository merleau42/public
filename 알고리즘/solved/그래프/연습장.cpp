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

// 자손 노드의 조상 노드를 찾는다 (노드가 소속된 서브 트리의 대표 노드)
int getParent(int node){
    if (parent[node] == node)
        return node;
    else
        return parent[node] = getParent(parent[node]);
}

// 두 노드가 공통의 조상을 갖도록한다 (노드 하나가 다른 트리에 흡수됨)
int unionParent(int nd1, int nd2){
    if ( getParent(nd1) < getParent(nd2) )
        parent[nd2] = getParent(nd1);
    else
        parent[nd1] = getParent(nd2);
}


// 대표 vertex만 보고 포함여부 판단
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

        if ( getParent(current.start) < getParent(current.arrive) ){
            parent[parent[current.arrive]] = parent[current.start];
            weight += current.cost;
        }
        else if ( getParent(current.start) > getParent(current.arrive) ){
            parent[parent[current.start]] = parent[current.arrive];
            weight += current.cost;
        }

        /*
        if ( getParent(current.start) != getParent(current.arrive) ){
            min (parent[current.arrive]] = parent[current.start]) ;
            weight += current.cost;
        }
        */
    }

    cout << weight;

    return 0;
}