using namespace std;
#include <bits/stdc++.h>
int n, k;
int m;

int main(){
    cin >> n >> k;

    int seq[100001];    // 수열
    for (int i=1; i<=n; i++)
    cin >> seq[i];


    int psum[100001];   // 누적합   (수열의 1항에서부터 N항까지의 합)
    psum[0] = 0;
    for (int i=1; i<=n; i++) 
    psum[i] = psum[i-1] + seq[i];



    int csum;           // 연속합   (수열의 N항에서부터 연속된 K개 항까지의 합)

    long mx=-100 * 1000000;
    for (int i=1; i<=n-k+1; i++)
        mx = max( mx, (long)psum[i+k-1] - psum[i-1] );

    cout << mx;
    return 0;
}