#include <bits/stdc++.h>
using namespace std;

struct A{
    int age;
    string name;

    bool operator< (const A &a) const{
        return this->age < a.age;
    }
    
};

int main(){
    int n; cin >> n;

    vector<A> V;

    for (int i=0; i<n; i++) {
        int a;
        string b;
        cin >> a;
        cin >> b;

        V.push_back({a,b});  //자동으로 A객체
    }

    //sort(V.begin(), V.end());
    stable_sort(V.begin(), V.end()); //e북

    for (int i=0; i<n; i++) {
        cout << V[i].age << " " << V[i].name << '\n';
    }

    return 0;
}