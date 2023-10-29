using namespace std;
#include <bits/stdc++.h>
//https://www.acmicpc.net/problem/1764

int main(){
    map<string, int> mp;
    string name;

    int heard, seen;
    cin >> heard >> seen;

    for (int i=0; i<heard; i++) {
        cin >> name;
        mp[name]++;
    }

    for (int i=0; i<seen; i++) {
        cin >> name;
        mp[name]++;
    }

    int hs=0;

    for (auto i : mp)
        if (i.second==2)
            hs++;

    cout << hs << '\n';

    for (auto i : mp)
        if (i.second==2)
            cout << i.first << '\n';

    return 0;
}