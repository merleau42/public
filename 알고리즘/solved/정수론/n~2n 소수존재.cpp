using namespace std;
#include <bits/stdc++.h>
#define NUM 246913
bool isPrime[NUM];
map<int,int> factor;

int main(){
    // 2부터 N까지 아직 판정되지 않음
    for (int i=2; i<=NUM; i++)
        isPrime[i]=true;

    // 1부터 N까지 판별 함수 구축
    for (int i=2; i<=NUM; i++)
        if ( isPrime[i]  )
            for (int j=2; j<=NUM/i; j++)
                isPrime[i*j] = false;

    int n;
    cin >> n;

    // M이상 N이하의 소수 출력
    while (n != 0){
        int sum=0;
        for (int i=n+1; i<=2*n; i++)
            if ( isPrime[i] )
                sum++;
        cout << sum << '\n';
        cin >> n;        
    }

    return 0;
}
