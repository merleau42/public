#include <bits/stdc++.h>
using namespace std;

int main(){
    queue<int> Q;

    int n;
    cin >> n;

    for (int i=0; i<n; i++){
        string str;
        cin >> str;

        if (str.compare("push")==0){
            int ps;
            cin >> ps;
            Q.push(ps);
        }

        else if (str.compare("front")==0){
            if (Q.empty()){
                cout << -1 << '\n';
            }
            else {
                cout << Q.front() << '\n';
            }
        }

        else if (str.compare("back")==0){
            if (Q.empty()){
                cout << -1 << '\n';
            }
            else {
                cout << Q.back() << '\n';
            }
        }

        else if (str.compare("pop")==0){
            if (Q.empty()){
                cout << -1 << '\n';
            }
            else {
                cout << Q.front() << '\n';
                Q.pop();
            }
        }
        
        else if (str.compare("empty")==0){
            cout << Q.empty() << '\n';
        }
        
        else if (str.compare("size")==0){
            cout << Q.size() << '\n';
        }
    }



    return 0;
}