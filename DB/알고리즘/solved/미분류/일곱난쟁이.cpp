using namespace std;
#include <bits/stdc++.h>
//https://www.acmicpc.net/problem/2309

int main(){
    int h[9];
    for (int i=0; i<9; i++) {
        cin >> h[i];
    }

    sort(h, h+9);
    do{
        int sum = 0;
        for (int i=0; i<7; i++)
            sum += h[i];
        if (sum==100)
            break;
    }while(next_permutation(h, h+9)); 

    for (int i=0; i<7; i++) {
        cout << h[i] << '\n';
    }

    return 0;
}