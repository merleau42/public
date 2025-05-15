using namespace std;
#include <bits/stdc++.h>

bool isPrime[10001];
vector<int> era;

int main(){
    int n;
    cin >> n;

    int k;
    cin >> k;
    int erased=0;

    for (int i=2; i<=n; i++)
        isPrime[i]=true;

    for (int i=2; i<=n; i++){
        if ( isPrime[i]  ){
            for (int j=1; j<=n/i; j++){
                if ( !isPrime[i*j] ){
                    isPrime[i*j] = false;
                    cout << ++erased << ": " << i*j << '\n';
                }
            }
            isPrime[i] = true;
        }
    }


    return 0;
}