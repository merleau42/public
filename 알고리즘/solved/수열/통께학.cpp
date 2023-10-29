using namespace std;
#include <bits/stdc++.h>
#define INF 987654321
#define CAP 500001


int n;      // 수열의 크기 (모든 항의 갯수)
int Q;      // 쿼리의 갯수
int T;      // 테스트 케이스의 갯수
int A,B;    // A항에서 B항까지
int k=2;    // A항부터 연속된 K개의 항

int seq[CAP];        // 수열의 원본
int sorted[CAP];     // 수열의 정렬본

bool VAL(pair<int, int>& a,pair<int, int>& b); // value순 정렬
map<int,int,VAL()> freq;   // 값들의 빈도를 기록

long psum[CAP];     // 누적합 (1항부터 n항까지의 합)

long rsum(int,int); // 구간합 (A항부터 B항까지의 합)
long csum(int,int); // 연속합 (A항부터 연속된 k개 항의 합)

long mean(int,int); // 산술 평균 (구간합을 항의 갯수로 나눈 값)
int median(int[]);  // 중앙값 (크기 순으로 나열할 때 중간에 오는 항)

int mode(map<int,int>);  // 최빈값 (가장 많이 존재하는 값)

void draw();

int main(){
    cin >> n;

    // 수열을 입력 받음
    for (int i=1; i<=n; i++){
        int term;
        cin >> term;
        seq[i]=term;
        sorted[i]=term;
        freq[term]++;
    }

    // 누적합 작성
    psum[0] = 0;
    for (int i=1; i<=n; i++)
        psum[i] = psum[i-1] + seq[i];

    // 정렬본 작성
    sort(sorted+1, sorted+n+1);

    cout << "\nㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n";

    cout << mean(1,n) << '\n';
    cout << median(sorted) << '\n';
    cout << mode(freq) << '\n';
    cout << sorted[n]-sorted[1] << '\n';

    cout << "\nㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n";

    for (auto i : freq) {
        cout << i.first << ": " << i.second << "개\n";
    }
    return 0;
}

// 구간합(A이상 B이하),  연속합(A포함 K개)
long rsum(int A, int B)  { return psum[B] - psum[A-1]; }
long csum(int A, int K)  { return psum[A+K-1] - psum[A-1]; }

// 평균, 중앙값, 최빈값
long mean(int A, int B)  { return rsum(A,B)/(B-A+1); }
int median(int sorted[]) { return sorted[n/2 + 1]; }
int mode(map<int,int> freq){
    int maxi;
    int mx = -INF; int sec;
    for (auto i : freq){
        if (i.second > mx){
            maxi = i.first;
            mx = i.second;
        }
    }
    return maxi;
}

bool VAL(pair<int, int>& a,pair<int, int>& b)
{	if (a.second == b.second) 
        return a.first < b.first;
    else
        return a.second < b.second;}

void draw(){
    cout << "\n정렬\t";
    for (int i=1; i<=n; i++)
        cout << sorted[i] << '\t';

    cout << "\n수열\t";
    for (int i=1; i<=n; i++)
        cout << seq[i] << '\t';
    
    cout << "\n누적합\t";
    for (int i=1; i<=n; i++)
        cout << psum[i] << '\t';

    cout << "\n평균" << "\t";
    cout << mean(1,n) << '\t';

    cout << "\n중앙값" << "\t";
    cout << median(sorted) << '\t';

    cout << "\n최빈값" << "\t";
    cout << mode(freq) << '\t';

    cout << "\n" << k << "연속합" << "\t";
    for (int i=1; i<=n-k+1; i++)
        cout << csum(i,k) << '\t';

    cout << "\nㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n";
}