using namespace std;
#include <bits/stdc++.h>
//https://www.acmicpc.net/problem/2979

int park[104];
int main(){
    int a, b, c;
    cin >> a >> b >> c;

    for (int i=0; i<3; i++) {
        int s, l;
        cin >> s >> l;
        for (int j=s; j<l; j++) {
            park[j]++;
        }
    }

    int sum=0, k=0;
    for (int i=0; i<100; i++) {
        k = a*1*(park[i]==1) + b*2*(park[i]==2) + c*3*(park[i]==3);
        sum += k;
    }

    cout << sum;
    return 0;
}