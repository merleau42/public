#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> v;

int main(){
    int a,b,n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &a, &b);
        v.push_back( {a,b} );
    }

    sort(v.begin(), v.end());

    for (pair<int,int> e:v)
        cout << e.first << " " << e.second << endl;

    return 0;
}