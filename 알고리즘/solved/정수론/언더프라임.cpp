using namespace std;
#include <bits/stdc++.h>
#define NUM 100001
bool isPrime[NUM];

vector<int> prime;    //x번쨰 소수 prime[x]
map<int,int> factor;  //x의 소인수 factor[x]

int main(){
    int A, B;
    cin >> A >> B;

    // 2부터 NUM까지 아직 판정되지 않음
    for (int i=2; i<=NUM; i++)
        isPrime[i]=true;

    // 1부터 NUM까지 판별 함수 구축
    for (int i=2; i<=NUM; i++)
        if ( isPrime[i]  )
            for (int j=2; j<=NUM/i; j++)
                isPrime[i*j] = false;

    int underPrime=0;
    for (int k=A; k<=B; k++) {
        factor.clear();
        // K의 소인수분해
        int tmp=k;
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

        int valSum=0;
        for (auto e: factor)
            valSum += e.second;

        if (isPrime[valSum])
            underPrime++;
    }

    cout << underPrime;

    return 0;
}