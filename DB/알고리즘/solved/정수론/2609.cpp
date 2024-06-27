#include <bits/stdc++.h>
using namespace std;


int* gonkyaksoo(int A, int B){

}

int *yaksoo(int N) {
  int ret[1000];
  int j = 0;

  for (int i = 1; i <= N; i++) {
    if (N % i == 0)
      ret[j++] = i;
  }

  return ret;
}

int main() {
  int N = 48;
  int i = 0, tmp;
  while ((tmp = yaksoo(N)[i++]) != 0) {
    cout << tmp << ' ';
  }
  return 0;
}