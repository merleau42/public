using namespace std;
#include <bits/stdc++.h>
#define NUM 4000001
bool isPrime[NUM];
vector<int> prime;    //x번쨰 소수 prime[x]
map<int,int> factor;  //x의 소인수 factor[x]

int main(){
    int A, B;
    string D;
    cin >> A >> B >> D;

    // 2부터 NUM까지 아직 판정되지 않음
    for (int i=2; i<=NUM; i++)
        isPrime[i]=true;

    // 1부터 NUM까지 판별 함수 구축
    for (int i=2; i<=NUM; i++)
        if ( isPrime[i]  )
            for (int j=2; j<=NUM/i; j++)
                isPrime[i*j] = false;

    // M이상 N이하의 소수 출력

    int cnt=0;
    for (int i=A; i<=B; i++)
        if ( isPrime[i] )
            if( to_string(i).find(D)!=string::npos )
                cnt++;
    
    cout << cnt;

    return 0;
}