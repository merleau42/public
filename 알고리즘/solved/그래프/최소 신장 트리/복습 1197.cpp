using namespace std;
#include <bits/stdc++.h>

bool visited[10001];

struct adjacent{
    int connected;
    int cost;

    bool operator< (const adjacent &adj) const{
        return {this->cost > adj.cost};
    }
};

int main(){
    int weight=0;
    int vertex, edge;
    cin >> vertex >> edge;

	vector<vector<adjacent>> Graph(vertex+1);    //Graph(x) == x라는 정점

    for (int i=1; i<=edge; i++) {
        int A, B, C;
        cin >> A >> B >> C;
        Graph[A].push_back( {B, C} );
        Graph[B].push_back( {A, C} );
    }

    priority_queue<adjacent> pq;   // 인접한 새로운 edge가 들어갈 공간

    pq.push({1, 0});

    while( !pq.empty() ){
        adjacent current = pq.top();
        pq.pop();

        if(visited[current.connected])
            continue;
        visited[current.connected]=true;

        weight += current.cost;

		for (adjacent i: Graph[current.connected]){   // 연결된 edge 들
			pq.push( i );
		}
    }

    cout << weight;

    return 0;
}
    //프림 ㅡ 현재까지 방문했던 모든 노드에 인접한 새로운 edge 중, 가중치가 젤 낮은 것 고르고, 최종 가중치에 합산