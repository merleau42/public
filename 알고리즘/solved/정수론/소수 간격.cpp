using namespace std;
#include <bits/stdc++.h>
#define NUM 1300000
bool isPrime[NUM];

int main(){
    int T;
    cin >> T;

    // 2부터 NUM까지 아직 판정되지 않음
    for (int i=2; i<=NUM; i++)
        isPrime[i]=true;

    // 1부터 NUM까지 판별 함수 구축
    for (int i=2; i<=NUM; i++)
        if ( isPrime[i]  )
            for (int j=2; j<=NUM/i; j++)
                isPrime[i*j] = false;;

    while (T--){
        int n;
        cin >> n;
        // M이상 N이하의 소수 출력
        int prevP;
        int nextP;

        for (int i=n; n/2<=i; i--){
            if ( isPrime[i] ){
                prevP=i;
                break;
            }
        }

        for (int i=n; i<=2*n; i++){
            if ( isPrime[i] ){
                nextP=i;
                break;
            }
        }
        cout << nextP - prevP << '\n';
    }
    return 0;
}




// https://www.acmicpc.net/problem/3896
// ( k이상 최소 소수 ) - ( k이하 최대 소수 )