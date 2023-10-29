using namespace std;
#include <bits/stdc++.h>

int n;
int A, B;
int T;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    // 수열의 항의 갯수
    cin >> n;
    cin >> T;
    int seq[100001];    // 수열
    int psum[100001];   // 누적합   (수열의 1항에서부터 N항까지의 합)

    for (int i=1; i<=n; i++)
        cin >> seq[i];
    
    psum[0] = 0;
    for (int i=1; i<=n; i++) 
        psum[i] = psum[i-1] + seq[i];

    while(T--){
        cin >> A >> B;
    
        int rsum;           // 구간합   (수열의 A항에서부터 B항까지의 합)
        rsum = psum[B] - psum[A-1];
        cout << rsum << '\n';
    }

    return 0;
}