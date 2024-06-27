using namespace std;
#include <bits/stdc++.h>
//https://www.acmicpc.net/problem/2312

bool isPrime[10001];
map<int,int> factor;

int main(){
    int n;
    cin >> n;

    // 2부터 N까지 아직 판정되지 않음
    for (int i=2; i<=n; i++)
        isPrime[i]=true;

    // 1부터 N까지 판별 함수 구축
    for (int i=2; i<=n; i++)
        if ( isPrime[i]  )
            for (int j=2; j<=n/i; j++)
                isPrime[i*j] = false;

    // N의 소인수분해
    int tmp=n;
    int i=1;
    while ( tmp!=1 ){
        i++;
        if ( isPrime[i] ){
            while ( tmp % i == 0 ){
                factor[i]++;
                tmp = tmp/i;
            }
        }
    }

    for (auto e: factor) {
        cout << e.first << ' ' << e.second << '\n';
    }

    

    return 0;
}

// 약수 판정
// i*(tmp/i) == tmp
// tmp%i == 0