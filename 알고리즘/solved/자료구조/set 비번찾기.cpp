using namespace std;
#include <bits/stdc++.h>
//https://www.acmicpc.net/problem/1764

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    map<string, string> mp;
    int n, q;
    cin >> n >> q;

    for (int i=0; i<n; i++) {
        string s1, s2;
        cin >> s1 >> s2;

        mp[s1]=s2;
    }

    for (int i=0; i<q; i++) {
        string s;
        cin >> s;
        cout << mp[s] << '\n';
    }

    return 0;
}