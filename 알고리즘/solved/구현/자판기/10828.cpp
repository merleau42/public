#include <bits/stdc++.h>
using namespace std;

int main(){
    stack<int> st;

    int n;
    cin >> n;

    for (int i=0; i<n; i++){
        string str;
        cin >> str;

        if (str.compare("push")==0){
            int ps;
            cin >> ps;
            st.push(ps);
        }

        else if (str.compare("top")==0){
            if (st.empty()){
                cout << -1 << '\n';
            }
            else {
                cout << st.top() << '\n';
            }
        }

        else if (str.compare("pop")==0){
            if (st.empty()){
                cout << -1 << '\n';
            }
            else {
                cout << st.top() << '\n';
                st.pop();
            }
        }
        
        else if (str.compare("empty")==0){
            cout << st.empty() << '\n';
        }
        
        else if (str.compare("size")==0){
            cout << st.size() << '\n';
        }
    }



    return 0;
}