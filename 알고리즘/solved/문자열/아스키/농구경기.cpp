using namespace std;
#include <bits/stdc++.h>
//https://www.acmicpc.net/problem/1159

int alpha[26];

int main(){
    int T; cin >> T;
    while(T--){
        string s;
        cin >> s;
        alpha[ s[0] - 'a' ]++;
    }

    bool match=false;
    for (int i=0; i<26; i++) {
        if ( alpha[i] >= 5 ){
            cout << (char)(i+'a');
            match=true;
        }
    }

    if (!match) cout << "PREDAJA";
    return 0;
}