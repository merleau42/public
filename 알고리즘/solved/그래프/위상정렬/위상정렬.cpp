using namespace std;
#include <bits/stdc++.h>

int duration[10001];
int indegree[10001]; // 갯수

struct task{
    int dur;
    int vertex;

    bool operator< (const task &cur) const{
        return this->dur > cur.dur;
    }
};

int main(){
    int v;
    cin >> v;

    vector<vector<int>> adjacent(v+1);
    priority_queue< task > pq;

    for (int i=1; i<=v; i++) {
        cin >> duration[i];
        cin >> indegree[i];
        for (int j=0; j < indegree[i]; j++) {
            int tmp;
            cin >> tmp;
            adjacent[tmp].push_back(i);
        }
        if (indegree[i]==0)
            pq.push( {duration[i], i} );
    }

    int record=0;
    while ( !pq.empty() ){
        task current = pq.top();
        pq.pop();

        record = current.dur;

        for (int cursor : adjacent[current.vertex]){
            indegree[cursor] -= 1;

            if (indegree[cursor]==0)
                pq.push( {record + duration[cursor],  cursor} );
        }
    }

    cout << record;

    return 0;
}
// 자기안으로 들어오는게 없는 노드를 선택 (하고 없애줌)
/*
1-x->2ㅡ>3ㅡ>4
        ㄴㅡ>5ㅡ>6
 
7ㅡ>8ㅡ>9
*/