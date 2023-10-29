using namespace std;
#include <bits/stdc++.h>
//https://www.acmicpc.net/problem/

int alpha[26];

int main(){
    string s;
    cin >> s;

    for (char c: s)
        alpha[c - 'a']++;

    for (int i=0; i<26; i++) {
        cout << alpha[i] <<' ';
    }
    return 0;
}