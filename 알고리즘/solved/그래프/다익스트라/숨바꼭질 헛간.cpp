//프림
//역대 방문 노드에 인접한 새로운 edge 중, 가중치가 젤 낮은 것 고르기
//최종 가중치에 합산

//다익
//모든 정점사이의 가중치를 행렬에 초기화
//역대 방문 노드에 인접한 새로운 edge 중, 가중치가 젤 낮은 것 고르기
//가중치 행렬을 갱신

using namespace std;
#include <bits/stdc++.h>

int dist[20001];        // 시작점에서부터 x점까지의 거리
int INF = 20001;

int main(){
    int v, e;
    cin >> v >> e;

    for (int i=1; i<=v; i++)
            dist[i]=INF;

    dist[1]=0;

	vector<vector<int>> Graph(v+1);    //Graph(x) == x라는 정점

    for (int i=1; i<=e; i++) {
        int A, B;
        cin >> A >> B;
        Graph[A].push_back(B);
        Graph[B].push_back(A);
    }

    queue<int> reserve;
    reserve.push(1);

    while( !reserve.empty() ){
        int current = reserve.front();
        reserve.pop();

        for (int i: Graph[current] ){
            if (dist[i] > dist[current]+1 ){
                dist[i] = dist[current]+1;
                reserve.push(i);
            }
        }
    }

    int h=1;
    int Dmx=0;
    int Hmx=1;
    for (int i=2; i<=v; i++) {
        if (dist[i] > Dmx){
            h=i;
            Dmx = dist[i];
            Hmx = 1;
        }
        else if (dist[i] == Dmx){
            Hmx++;
        }
    }

    // 숨을 헛간, 거리(mx), 같은 거리 헛간들수
    cout << h << " " << Dmx << " " << Hmx;

    return 0;
}