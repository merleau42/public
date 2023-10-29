using namespace std;
#include <bits/stdc++.h>
#define NUM -1
bool isPrime[NUM];

vector<int> prime;    //x번쨰 소수 prime[x]
map<int,int> factor;  //x의 소인수 factor[x]
int gcd(int,int);     //두 수의 최대공약수
int lcm(int,int);     //두 수의 최소공배수

int main(){
    int n, m;
    cin >> n;

    // 2부터 NUM까지 아직 판정되지 않음
    for (int i=2; i<=NUM; i++)
        isPrime[i]=true;

    // 1부터 NUM까지 판별 함수 구축
    for (int i=2; i<=NUM; i++)
        if ( isPrime[i]  )
            for (int j=2; j<=NUM/i; j++)
                isPrime[i*j] = false;

    // N이하의 소수 집합
    for (int i=1; i<=n; i++)
        if ( isPrime[i] )
            prime.push_back( i );

    // M이상 N이하의 소수 출력
    for (int i=m; i<=n; i++)
        if ( isPrime[i] )
            cout << i << '\n';

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

    // 소인수 분해 출력
    for (auto e: factor) {
        cout << e.first << '^' << e.second << '\n';
    }
    return 0;
}

// 최대공약수 (유클리드 호제법)
int gcd(int a, int b){
	int mod = a%b;
    
	while (mod > 0){
		a = b;
		b = mod;
		mod = a%b;
	}
	
    return b;
}

// 최소공배수
int lcm(int a, int b){
    return a*b/gcd(a,b);
}
