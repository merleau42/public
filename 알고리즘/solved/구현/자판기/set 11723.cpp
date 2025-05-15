#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    set<int> st;

    int n;
    cin >> n;

    for (int i=0; i<n; i++){
        string order;
        int order2;
        cin >> order;

        if (order == "all")
            st={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};

        else if (order == "empty")  st.clear();
        
        else{
            cin >> order2;

            if (order == "add")
                st.insert(order2);

            if (order == "remove")
                st.erase(order2);

            if (order == "check")
                cout << st.count(order2) << '\n';

            if (order == "toggle"){      
                if (st.count(order2))
                    st.erase(order2);
                else
                    st.insert(order2);
            }
        }
    }

    return 0;
}