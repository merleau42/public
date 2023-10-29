using namespace std;
#include <bits/stdc++.h>

int duration[501];
int indegree[501]; // 갯수
int timeattack[501];

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
        int m;
        cin >> m;
        while( m!=-1 ){
            adjacent[m].push_back(i);
            indegree[i]++; // 중복제공되지 않으므로
            cin >> m;
        }
        if (indegree[i]==0)
            pq.push( {duration[i], i} );
    }

    int record=0;
    while ( !pq.empty() ){
        task current = pq.top();
        pq.pop();

        record = current.dur;
        timeattack[current.vertex] = record;

        for (int cursor : adjacent[current.vertex]){
            indegree[cursor] -= 1;

            if (indegree[cursor]==0)
                pq.push( {record + duration[cursor],  cursor} );
        }
    }

    for (int i=1; i<=v; i++) {
        cout << timeattack[i] << '\n';
    }

    return 0;
}