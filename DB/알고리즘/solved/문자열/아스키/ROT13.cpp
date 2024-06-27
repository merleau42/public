using namespace std;
#include <bits/stdc++.h>
//https://www.acmicpc.net/problem/11165

int main(){
    string s;
    getline(cin, s);

    for (char c : s)
        if      (c >= 'a') cout << char((13+c) - 26*(c+13 > 'z'));
        else if (c >= 'A') cout << char((13+c) - 26*(c+13 > 'Z'));
        else               cout << c;
    return 0;
}