using namespace std;
#include <bits/stdc++.h>
//https://www.acmicpc.net/problem/10988

int main(){
    string a, b;
    cin >> a;
    b = a;
    reverse(a.begin(), a.end());

    cout << (a==b) ? 1 : 0;
    return 0;
}