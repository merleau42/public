using namespace std;
#include <bits/stdc++.h>
#define INF 987654321
#define CAP 1000001

int mx;
int n, k;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int seq[CAP];    // 수열
    cin >> n >> k;
    for (int i=1; i<=n; i++){
        int tmp;
        cin >> tmp;
        seq[i] = (tmp==1);
    }

    int psum[CAP];   // 누적합   (수열의 1항에서부터 N항까지의 합)
    psum[0] = 0;
    for (int i=1; i<=n; i++) 
        psum[i] = psum[i-1] + seq[i];


    mx = -INF;
    for (int w=k; w<=n; w++) {
        for (int i=1; i<=n-w+1; i++)
            mx = max( mx, psum[i+w-1] - psum[i-1] );
            if (mx >= k){
                cout << w;
                return 0;
            }
    }
    
    cout << -1;
    return 0;
}

/*

연속합이 3이되는가?
w           1000101001
3슬라이드          ---
4슬라이드         ---- x
5슬라이드        ----- x
6슬라이드       ------ o
...
n슬라이드   ---------- o


x3x1x2x
     --(2,1)
    ---(3,2)
   ----(5,2)
  -----(6,3)


연속합이 5가되는가?
1010100100011100010001001
x1x1x2x3xxx3x3x2x
-----------------(25L, 10x)
 ----------------(24, 9)
---------------(, )
 
*/