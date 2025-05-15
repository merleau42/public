#include <bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);

    priority_queue<int> pq;

    int n; 
    cin >> n;

    for (int i=0; i<n; i++) {
        int m;
        cin >> m;

        if (m==0){
            if (pq.empty()){
                cout << "0\n";
            }
            else {
                cout << -pq.top() << '\n';
                pq.pop();
            }
        }

        else {
            pq.push(-m);
        }
    }

    return 0;
}