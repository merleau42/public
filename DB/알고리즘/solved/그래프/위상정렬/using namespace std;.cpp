using namespace std;
#include <bits/stdc++.h>
//https://www.acmicpc.net/problem/2529
int indegreeA[10];
int indegreeB[10];
int maxser[10];
int minser[10];

int main(){
    int v;
    cin >> v;

    vector<vector<int>> Graph(v+1);
    for (int i=0; i<v; i++) {
        char w;
        cin >> w;
        if (w=='>'){
            Graph[i].push_back(i+1);
            indegreeA[i+1]++;
            indegreeB[i+1]++;
        }
        else{
            Graph[i+1].push_back(i);
            indegreeA[i]++;  
            indegreeB[i]++;           
        }
    }
    priority_queue<int, vector<int>, greater<int>> maxx;
    priority_queue<int> minn;
    for (int i=0; i<v+1; i++) {
        if (indegreeA[i]==0){
            maxx.push( i );
            minn.push( i );
        }
    }
    int now=9;
    while ( !maxx.empty() ){
        int current = maxx.top();
        maxx.pop();

        maxser[current] = now--;

        for (int i : Graph[current]){
            indegreeA[i]--;
            if ( indegreeA[i]==0 ){
                maxx.push( i );
            }
        }
    }
    now=v;
    while ( !minn.empty() ){
        int current = minn.top();
        minn.pop();

        minser[current] = now--;

        for (int i : Graph[current]){
            indegreeB[i]--;
            if ( indegreeB[i]==0 ){
                minn.push( i );
            }
        }
    }
    return 0;
}

/*
abcdef
ㅡ d<c<b<a>f<e
ㅡ f<e<d<b>c<a
*/