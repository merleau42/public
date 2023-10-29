#include <bits/stdc++.h>
using namespace std;


int main(){
    int n, k;
    cin >> n >> k;

    queue<int> Q;

    for (int i=1; i<=n; i++){
        Q.push(i);
    }

    vector<int> V;

    while ( !Q.empty() ){
        for (int i=0; i<k-1; i++){
            int tmp = Q.front();
            Q.pop();
            Q.push(tmp);
        }
        V.push_back(Q.front());
        Q.pop();
    }

    cout << "<" << V[0];
    
    for (int i=1; i<n; i++){
        cout << ", " << V[i];
    }

    cout << ">" << endl;

    return 0;
}