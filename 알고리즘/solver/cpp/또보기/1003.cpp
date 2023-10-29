#include <bits/stdc++.h>
using namespace std;
// https://www.acmicpc.net/problem/1003


int arr[41][2];

//[x][] : x 구할 피보나치
//[x][] : x 구할 피보나치
//a[][y] = r-value : y 출력된 횟수

void fibonacci(int n) {
    // 0이 출력된 횟수
    arr[0][0] = 1;
    arr[1][0] = 0;
    
    // 1이 출력된 횟수
    arr[0][1] = 0;
    arr[1][1] = 1;

    for (int i=2; i<=n; i++) {
        arr[i][0] = arr[i-1][0] + arr[i-2][0];
        arr[i][1] = arr[i-1][1] + arr[i-2][1];
    }

    cout << arr[n][0] << ' ' << arr[n][1] << '\n';
}


int main(){
    int t;
    cin >> t;

    for (int i=0; i<t; i++) {
        int n;
        cin >> n;
        fibonacci(n);
    }


    return 0;
}