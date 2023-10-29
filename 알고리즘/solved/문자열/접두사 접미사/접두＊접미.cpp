using namespace std;
#include <bits/stdc++.h>
//https://www.acmicpc.net/problem/9996

int main(){
    int n;
    string fix;
    cin >> n >> fix;

    int wild = fix.find("*");
    regex re( fix.substr(0, wild) + ".*" + fix.substr(wild+1) );
    
    string s[100];
    for (int i=0; i<n; i++) {
        cin >> s[i];
    }

    for (int i=0; i<n; i++) {
        cout << (( regex_match(s[i], re) ) ? "DA\n" : "NE\n") ;
    }

    return 0;
}