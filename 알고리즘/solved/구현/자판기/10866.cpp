#include <bits/stdc++.h>
using namespace std;

int main(){
    deque<int> deq;

    int n;
    cin >> n;

    for (int i=0; i<n; i++){
        string str;
        cin >> str;

        if (str == "push_front"){
            int ps;
            cin >> ps;
            deq.push_front(ps);
        }

        if (str == "push_back"){
            int ps;
            cin >> ps;
            deq.push_back(ps);
        }

        else if (str == "front"){
            if (deq.empty()){
                cout << -1 << '\n';
            }
            else {
                cout << deq.front() << '\n';
            }
        }

        else if (str == "back"){
            if (deq.empty()){
                cout << -1 << '\n';
            }
            else {
                cout << deq.back() << '\n';
            }
        }

        else if (str == "pop_front"){
            if (deq.empty()){
                cout << -1 << '\n';
            }
            else {
                cout << deq.front() << '\n';
                deq.pop_front();
            }
        }

        else if (str == "pop_back"){
            if (deq.empty()){
                cout << -1 << '\n';
            }
            else {
                cout << deq.back() << '\n';
                deq.pop_back();
            }
        }
        
        else if (str == "empty"){
            cout << deq.empty() << '\n';
        }
        
        else if (str == "size"){
            cout << deq.size() << '\n';
        }
    }



    return 0;
}