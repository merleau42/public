using namespace std;
#include <bits/stdc++.h>

bool isPrime[1000001];

int main(){
    int m, n;
    cin >> m >> n;

    // 2부터 N까지 아직 판정되지 않음
    for (int i=2; i<=n; i++)
        isPrime[i]=true;

    // 1부터 N까지 판별 함수 구축
    for (int i=2; i<=n; i++)
        if ( isPrime[i]  )
            for (int j=2; j<=n/i; j++)
                isPrime[i*j] = false;

    // N이하의 소수 출력
    for (int i=m; i<=n; i++)
        if ( isPrime[i] )
            cout << i << '\n';
    return 0;
}